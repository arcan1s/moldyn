/**
 * @file
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn reading_coords
 */
int reading_coords (const int mode, const char *filename, const int type_inter, 
                    const int *label_atom, const float *cell, int *num_mol, 
                    int *num_atoms, int *true_label_mol, int *label_mol, 
                    int *type_atoms, float *coords, char *ch_type_atoms)
/**
 * @brief function that reads coordinates from special file format
 * @code
 * reading_coords (0, filename, type_inter, label_atom, cell, &num_mol, 
 *                 &num_atoms, true_label_mol, label_mol, type_atoms, 
 *                 coords, ch_type_atoms);
 * @endcode
 * 
 * @param mode            mode of reading; '1' is statgen, '2' is envir or 
 *                        frad, '3' is agl
 * @param filename        input file name
 * @param type_inter      number of needed atoms
 *                        (number of needed molecules)
 * @param label_atom      massive of needed atom types
 *                        (massive of needed molecules)
 * @param cell            massive of cell size
 * @param num_mol         number of molecules
 * @param num_atoms       number of atoms
 * @param true_label_mol  massive of true numbers of molecule for atoms
 * @param label_mol       massive of numbers of molecule for atoms
 * @param type_atoms      massive of atom types
 * @param coords          massive of coordinates
 * @param ch_type_atoms   massive of char atom types
 * 
 * @return 1              - file $filename does not exist
 * @return 2              - unknown mode
 * @return 0              - exit without errors
 */
{
  char at_symb[32], file_string[256];
  int atoms, cur_at_num, cur_at_type, cur_mol, i, j, tr_num_atoms, ref_mol, x, y;
  float cur_coords[3], *not_tr_coords, ref[3];
  FILE *inp;
  
/* cur_*                  temp variables
 * at_symb                temp variable
 * file_string            temp string variable
 * atoms                  total number of atoms in system
 * tr_num_atoms           number of translated atoms (must be 8*num_atoms)
 * ref_mol                number of molecule for reference in translation
 * not_tr_coords          massive of not translated coordinates
 * ref                    massive of coordinates of reference molecule
 * inp                    input file
 */
  
/// <b>Work blocks</b>
  
  *num_atoms = 0;
  *num_mol = 0;
  
/// <pre>   reading file </pre>
  inp = fopen (filename, "r");
  if (inp == NULL)
    return 1;
  
  ref_mol = -1;
  fscanf (inp, "%i", &atoms);
  not_tr_coords = (float *) malloc (3 * atoms * sizeof (float));
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
            not_tr_coords[3**num_atoms+0] = cur_coords[0];
            not_tr_coords[3**num_atoms+1] = cur_coords[1];
            not_tr_coords[3**num_atoms+2] = cur_coords[2];
            
            if (ref_mol != cur_mol)
            {
              ref_mol = cur_mol;
              true_label_mol[*num_mol] = ref_mol;
              *num_mol = *num_mol + 1;
            }
            label_mol[*num_atoms] = *num_mol - 1;
            type_atoms[*num_atoms] = j;
            
            *num_atoms = *num_atoms + 1;
          }
        break;
      case 1:
// mode == 1 (all atoms)
        not_tr_coords[3**num_atoms+0] = cur_coords[0];
        not_tr_coords[3**num_atoms+1] = cur_coords[1];
        not_tr_coords[3**num_atoms+2] = cur_coords[2];
        ch_type_atoms[2**num_atoms+0] = at_symb[0];
        ch_type_atoms[2**num_atoms+1] = at_symb[1];
        
        if (ref_mol != cur_mol)
        {
          ref_mol = cur_mol;
          true_label_mol[*num_mol] = ref_mol;
          *num_mol = *num_mol + 1;
        }
        label_mol[*num_atoms] = *num_mol - 1;
        type_atoms[*num_atoms] = j;
        
        *num_atoms = *num_atoms + 1;
        break;
      case 2:
// mode == 2 (selected molecules)
        for (j=0; j<type_inter; j++)
          if (cur_mol == label_atom[j])
          {
            not_tr_coords[3**num_atoms+0] = cur_coords[0];
            not_tr_coords[3**num_atoms+1] = cur_coords[1];
            not_tr_coords[3**num_atoms+2] = cur_coords[2];
            ch_type_atoms[2**num_atoms+0] = at_symb[0];
            ch_type_atoms[2**num_atoms+1] = at_symb[1];
            
            if (ref_mol != cur_mol)
            {
              ref_mol = cur_mol;
              true_label_mol[*num_mol] = ref_mol;
              *num_mol = *num_mol + 1;
            }
            label_mol[*num_atoms] = *num_mol - 1;
            type_atoms[*num_atoms] = j;
            
            *num_atoms = *num_atoms + 1;
          }
        break;
      default: return 2;
    }
  }
  fclose (inp);
  
/// <pre>   translation </pre>
  tr_num_atoms = *num_atoms;
  for (i=0; i<*num_atoms; i++)
    for (j=0; j<3; j++)
      coords[3*i+j] = not_tr_coords[3*i+j];
  
// assign initial value to reference coordinates
  ref_mol = label_mol[0];
  for (i=0; i<3; i++)
    ref[i] = coords[3*0+i];
  
  for (i=0; i<*num_atoms; i++)
  {
    if (label_mol[i] != ref_mol)
    {
      ref_mol = label_mol[i];
      for (j=0; j<3; j++)
        ref[j] = not_tr_coords[3*i+j];
    }
    
    for (x=0; x<3; x++)
    {
      if (ref[x] >= 0.0)
// if xyz >= 0.0 A
     {
        for (j=0; j<3; j++)
          if (j == x)
            coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j] - cell[j];
          else
            coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j];
        
        label_mol[tr_num_atoms] = label_mol[i];
        type_atoms[tr_num_atoms] = type_atoms[i];
        tr_num_atoms++;
      }
      else
// if xyz < 0.0 A
      {
        for (j=0; j<3; j++)
          if (j == x)
            coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j] + cell[j];
          else
            coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j];
        
        label_mol[tr_num_atoms] = label_mol[i];
        type_atoms[tr_num_atoms] = type_atoms[i];
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
              coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j] - cell[j];
            else
              coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j];
        
          label_mol[tr_num_atoms] = label_mol[i];
          type_atoms[tr_num_atoms] = type_atoms[i];
          tr_num_atoms++;
        }
        
        if ((ref[x] < 0.0) && (ref[y] < 0.0))
// if xyz and xyz < 0.0 A
        {
          for (j=0; j<3; j++)
            if ((j == x) || (j == y))
              coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j] + cell[j];
            else
              coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j];
        
          label_mol[tr_num_atoms] = label_mol[i];
          type_atoms[tr_num_atoms] = type_atoms[i];
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
              coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j] + cell[j];
            if (j == y)
              coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j] - cell[j];
            if ((j != x) && (j != y))
              coords[3*tr_num_atoms+j] = not_tr_coords[3*i+j];
          }
          
          label_mol[tr_num_atoms] = label_mol[i];
          type_atoms[tr_num_atoms] = type_atoms[i];
          tr_num_atoms++;
        }
    }
    
    if ((ref[0] >= 0.0) && (ref[1] >= 0.0) && (ref[2] >= 0.0))
// if x and y and z >= 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] - cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] - cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] >= 0.0) && (ref[2] < 0.0))
// if x and y >= 0.0 A and z < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] - cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] + cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] < 0.0) && (ref[2] >= 0.0))
// if x and z >= 0.0 A and y < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] + cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] - cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] >= 0.0) && (ref[2] >= 0.0))
// if y and z >= 0.0 A and x < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] - cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] - cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] < 0.0) && (ref[2] >= 0.0))
// if x and y < 0.0 A and z >= 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] + cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] - cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] >= 0.0) && (ref[2] < 0.0))
// if x and z < 0.0 A and y >= 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] - cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] + cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] < 0.0) && (ref[2] < 0.0))
// if x >= 0.0 A and y and z < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] + cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] + cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] < 0.0) && (ref[2] < 0.0))
// if x and y and z < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] + cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] + cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
  }
  
/// <pre>   free memory </pre>
  free (not_tr_coords);
  
  return 0;
}