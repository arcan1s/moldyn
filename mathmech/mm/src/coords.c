/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file coords.c
 * Source code of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include <stdio.h>
#include <stdlib.h>

#include <mathmech/coords.h>


/**
 * @fn reading_coords
 */
int reading_coords (const int mode, const char *filename, const int type_inter, 
                    const int *label_atom, system_info *_system_info, 
                    int *true_label_mol, atom_info *_atom_info)
{
  char at_symb[32], file_string[256];
  int atoms, cur_at_num, cur_at_type, cur_mol, i, j, tr_num_atoms, ref_mol, x, y;
  float cur_coords[3], ref[3];
  FILE *inp;
  
/* cur_*                  temp variables
 * at_symb                temp variable
 * file_string            temp string variable
 * atoms                  total number of atoms in system
 * tr_num_atoms           number of translated atoms (must be 8(*_system_info).num_atoms)
 * ref_mol                number of molecule for reference in translation
 * ref                    massive of coordinates of reference molecule
 * inp                    input file
 */
  
/// <b>Work blocks</b>
  
  (*_system_info).num_atoms = 0;
  (*_system_info).num_mol = 0;
  
/// <pre>   reading file </pre>
  inp = fopen (filename, "r");
  if (inp == NULL)
    return 1;
  
  ref_mol = -1;
  fscanf (inp, "%i", &atoms);
  fgets (file_string, 256, inp);
  for (i=0; i<atoms; i++)
  {
    fgets (file_string, 256, inp);
    sscanf (file_string, "%i%s%f%f%f%i%i", &cur_at_num, at_symb, &cur_coords[0], 
            &cur_coords[1], &cur_coords[2], &cur_at_type, &cur_mol);
    
// reading variables according to selected mode
    switch (mode)
    {
      case 0:
// mode == 0 (selected atoms)
        for (j=0; j<type_inter; j++)
          if (cur_at_type == label_atom[j])
          {
            _atom_info[(*_system_info).num_atoms].coords[0] = cur_coords[0];
            _atom_info[(*_system_info).num_atoms].coords[1] = cur_coords[1];
            _atom_info[(*_system_info).num_atoms].coords[2] = cur_coords[2];
            _atom_info[(*_system_info).num_atoms].ch_type_atoms[0] = at_symb[0];
            _atom_info[(*_system_info).num_atoms].ch_type_atoms[1] = at_symb[1];
            
            if (ref_mol != cur_mol)
            {
              ref_mol = cur_mol;
              true_label_mol[(*_system_info).num_mol] = ref_mol;
              (*_system_info).num_mol = (*_system_info).num_mol + 1;
            }
            _atom_info[(*_system_info).num_atoms].label_mol = (*_system_info).num_mol - 1;
            _atom_info[(*_system_info).num_atoms].type_atoms = j;
            
            (*_system_info).num_atoms = (*_system_info).num_atoms + 1;
          }
        break;
      case 1:
// mode == 1 (all atoms)
        _atom_info[(*_system_info).num_atoms].coords[0] = cur_coords[0];
        _atom_info[(*_system_info).num_atoms].coords[1] = cur_coords[1];
        _atom_info[(*_system_info).num_atoms].coords[2] = cur_coords[2];
        _atom_info[(*_system_info).num_atoms].ch_type_atoms[0] = at_symb[0];
        _atom_info[(*_system_info).num_atoms].ch_type_atoms[1] = at_symb[1];
        
        if (ref_mol != cur_mol)
        {
          ref_mol = cur_mol;
          true_label_mol[(*_system_info).num_mol] = ref_mol;
          (*_system_info).num_mol = (*_system_info).num_mol + 1;
        }
        _atom_info[(*_system_info).num_atoms].label_mol = (*_system_info).num_mol - 1;
        _atom_info[(*_system_info).num_atoms].type_atoms = j;
        
        (*_system_info).num_atoms = (*_system_info).num_atoms + 1;
        break;
      case 2:
// mode == 2 (selected molecules)
        for (j=0; j<type_inter; j++)
          if (cur_mol == label_atom[j])
          {
            _atom_info[(*_system_info).num_atoms].coords[0] = cur_coords[0];
            _atom_info[(*_system_info).num_atoms].coords[1] = cur_coords[1];
            _atom_info[(*_system_info).num_atoms].coords[2] = cur_coords[2];
            _atom_info[(*_system_info).num_atoms].ch_type_atoms[0] = at_symb[0];
            _atom_info[(*_system_info).num_atoms].ch_type_atoms[1] = at_symb[1];
            
            if (ref_mol != cur_mol)
            {
              ref_mol = cur_mol;
              true_label_mol[(*_system_info).num_mol] = ref_mol;
              (*_system_info).num_mol = (*_system_info).num_mol + 1;
            }
            _atom_info[(*_system_info).num_atoms].label_mol = (*_system_info).num_mol - 1;
            _atom_info[(*_system_info).num_atoms].type_atoms = j;
            
            (*_system_info).num_atoms = (*_system_info).num_atoms + 1;
          }
        break;
      default: return 2;
    }
  }
  fclose (inp);
  
/// <pre>   translation </pre>
  tr_num_atoms = (*_system_info).num_atoms;
  
// assign initial value to reference coordinates
  ref_mol = _atom_info[0].label_mol;
  for (i=0; i<3; i++)
    ref[i] = _atom_info[0].coords[i];
  
  for (i=0; i<(*_system_info).num_atoms; i++)
  {
    if (_atom_info[i].label_mol != ref_mol)
    {
      ref_mol = _atom_info[i].label_mol;
      for (j=0; j<3; j++)
        ref[j] = _atom_info[i].coords[j];
    }
    
    for (x=0; x<3; x++)
    {
      if (ref[x] >= 0.0)
// if xyz >= 0.0 A
     {
        for (j=0; j<3; j++)
          if (j == x)
            _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j] - (*_system_info).cell[j];
          else
            _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j];
        
        _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
        _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
        _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
        _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
        tr_num_atoms++;
      }
      else
// if xyz < 0.0 A
      {
        for (j=0; j<3; j++)
          if (j == x)
            _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j] + (*_system_info).cell[j];
          else
            _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j];
        
        _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
        _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
        _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
        _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
        tr_num_atoms++;
      }
    }
    
    for (x=0; x<3; x++)
    {
      for (y=x+1; y<3; y++)
      {
        if ((ref[x] >= 0.0) && (ref[y] >= 0.0))
// if xyz and xyz >= 0.0 A
        {
          for (j=0; j<3; j++)
            if ((j == x) || (j == y))
              _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j] - (*_system_info).cell[j];
            else
              _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j];
        
          _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
          _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
          _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
          _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
          tr_num_atoms++;
        }
        
        if ((ref[x] < 0.0) && (ref[y] < 0.0))
// if xyz and xyz < 0.0 A
        {
          for (j=0; j<3; j++)
            if ((j == x) || (j == y))
              _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j] + (*_system_info).cell[j];
            else
              _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j];
        
          _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
          _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
          _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
          _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
          tr_num_atoms++;
        }
      }
      
      for (y=0; y<3; y++)
        if ((ref[x] < 0.0) && (ref[y] >= 0.0))
// if xyz OR xyz >= 0.0
        {
          for (j=0; j<3; j++)
          {
            if (j == x)
              _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j] + (*_system_info).cell[j];
            if (j == y)
              _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j] - (*_system_info).cell[j];
            if ((j != x) && (j != y))
              _atom_info[tr_num_atoms].coords[j] = _atom_info[i].coords[j];
          }
          
          _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
          _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
          _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
          _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
          tr_num_atoms++;
        }
    }
    
    if ((ref[0] >= 0.0) && (ref[1] >= 0.0) && (ref[2] >= 0.0))
// if x and y and z >= 0.0 A
    {
      _atom_info[tr_num_atoms].coords[0] = _atom_info[i].coords[0] - (*_system_info).cell[0];
      _atom_info[tr_num_atoms].coords[1] = _atom_info[i].coords[1] - (*_system_info).cell[1];
      _atom_info[tr_num_atoms].coords[2] = _atom_info[i].coords[2] - (*_system_info).cell[2];
      
      _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
      _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
      _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
      _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] >= 0.0) && (ref[2] < 0.0))
// if x and y >= 0.0 A and z < 0.0 A
    {
      _atom_info[tr_num_atoms].coords[0] = _atom_info[i].coords[0] - (*_system_info).cell[0];
      _atom_info[tr_num_atoms].coords[1] = _atom_info[i].coords[1] - (*_system_info).cell[1];
      _atom_info[tr_num_atoms].coords[2] = _atom_info[i].coords[2] + (*_system_info).cell[2];
      
      _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
      _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
      _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
      _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] < 0.0) && (ref[2] >= 0.0))
// if x and z >= 0.0 A and y < 0.0 A
    {
      _atom_info[tr_num_atoms].coords[0] = _atom_info[i].coords[0] - (*_system_info).cell[0];
      _atom_info[tr_num_atoms].coords[1] = _atom_info[i].coords[1] + (*_system_info).cell[1];
      _atom_info[tr_num_atoms].coords[2] = _atom_info[i].coords[2] - (*_system_info).cell[2];
      
      _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
      _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
      _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
      _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] >= 0.0) && (ref[2] >= 0.0))
// if y and z >= 0.0 A and x < 0.0 A
    {
      _atom_info[tr_num_atoms].coords[0] = _atom_info[i].coords[0] + (*_system_info).cell[0];
      _atom_info[tr_num_atoms].coords[1] = _atom_info[i].coords[1] - (*_system_info).cell[1];
      _atom_info[tr_num_atoms].coords[2] = _atom_info[i].coords[2] - (*_system_info).cell[2];
      
      _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
      _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
      _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
      _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] < 0.0) && (ref[2] >= 0.0))
// if x and y < 0.0 A and z >= 0.0 A
    {
      _atom_info[tr_num_atoms].coords[0] = _atom_info[i].coords[0] + (*_system_info).cell[0];
      _atom_info[tr_num_atoms].coords[1] = _atom_info[i].coords[1] + (*_system_info).cell[1];
      _atom_info[tr_num_atoms].coords[2] = _atom_info[i].coords[2] - (*_system_info).cell[2];
      
      _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
      _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
      _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
      _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] >= 0.0) && (ref[2] < 0.0))
// if x and z < 0.0 A and y >= 0.0 A
    {
      _atom_info[tr_num_atoms].coords[0] = _atom_info[i].coords[0] + (*_system_info).cell[0];
      _atom_info[tr_num_atoms].coords[1] = _atom_info[i].coords[1] - (*_system_info).cell[1];
      _atom_info[tr_num_atoms].coords[2] = _atom_info[i].coords[2] + (*_system_info).cell[2];
      
      _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
      _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
      _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
      _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] < 0.0) && (ref[2] < 0.0))
// if x >= 0.0 A and y and z < 0.0 A
    {
      _atom_info[tr_num_atoms].coords[0] = _atom_info[i].coords[0] - (*_system_info).cell[0];
      _atom_info[tr_num_atoms].coords[1] = _atom_info[i].coords[1] + (*_system_info).cell[1];
      _atom_info[tr_num_atoms].coords[2] = _atom_info[i].coords[2] + (*_system_info).cell[2];
      
      _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
      _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
      _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
      _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] < 0.0) && (ref[2] < 0.0))
// if x and y and z < 0.0 A
    {
      _atom_info[tr_num_atoms].coords[0] = _atom_info[i].coords[0] + (*_system_info).cell[0];
      _atom_info[tr_num_atoms].coords[1] = _atom_info[i].coords[1] + (*_system_info).cell[1];
      _atom_info[tr_num_atoms].coords[2] = _atom_info[i].coords[2] + (*_system_info).cell[2];
      
      _atom_info[tr_num_atoms].label_mol = _atom_info[i].label_mol;
      _atom_info[tr_num_atoms].type_atoms = _atom_info[i].type_atoms;
      _atom_info[tr_num_atoms].ch_type_atoms[0] = _atom_info[i].ch_type_atoms[0];
      _atom_info[tr_num_atoms].ch_type_atoms[1] = _atom_info[i].ch_type_atoms[1];
      tr_num_atoms++;
    }
  }
  
  return 0;
}
