/* Library for reading coordinates from input file
 * 
 * Usage:
 *                    reading_coords (filename, type_interaction, labels, cell, 
 *  &number_of_molecules, &number_of_atoms, true_label_molecule, label_molecule, 
 *                                                           type_atoms, coords)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char conv (int fnumb, int dig_pos)
{
  int d, h, o;
  char const digit[] = "0123456789";
 
  h = fnumb / 100;
  d = (fnumb % 100) / 10;
  o = fnumb % 10;

  if (dig_pos == 1) return digit[o];
  if (dig_pos == 2) return digit[d];
  if (dig_pos == 3) return digit[h];
  else return digit[0];
}


int reading_coords (char *filename, int type_inter, const int *label_atom, 
                    const float *cell, int *num_mol, int *num_atoms, 
                    int *true_label_mol, int *label_mol, 
                    int *type_atoms, float *coords)
/* filename         - name of file with coordinates
 * type_inter       - type interaction (number of molecules for interaction)
 * label_atom       - types of atom for interaction
 * cell             - cell dimension
 * num_mol          - number of molecules for writing coordinates
 * num_atoms        - number of atoms for writing coordinates
 * true_label_mol   - massive of true numbers of molecule for atoms
 * label_mol        - massive of numbers of molecule for atoms
 * type_atoms       - massive of atom types for atoms
 * coords           - massive of coordinates
 */
{
  char file_string[256];
  int atoms, i, j, tr_num_atoms, ref_mol, x, y, z;
  float not_tr_coords[750000], ref[3];
  FILE *inp;
/* file_string      - temp string variable
 * atoms            - total number of atoms in system
 * tr_num_atoms     - number of translated atoms for writing coordinates (m.b. 8*num_atoms)
 * ref_mol          - number of molecule for reference
 * not_tr_coords    - not translated coordinates
 * ref              - coordinates of reference molecule
 * inp              - file with input data
 */
  
  *num_atoms = 0;
  *num_mol = 0;
  
//   Reading file
  inp = fopen (filename, "r");
  if (inp == NULL)
    return 1;
  
  ref_mol = -1;
  fscanf (inp, "%i", &atoms);
  for (i=0; i<atoms; i++)
  {
    fgets (file_string, 256, inp);
    
    for (j=0; j<type_inter; j++)
      if (atoi (&file_string[47]) == label_atom[j])
      {
        not_tr_coords[3**num_atoms+0] = atof (&file_string[10]);
        not_tr_coords[3**num_atoms+1] = atof (&file_string[23]);
        not_tr_coords[3**num_atoms+2] = atof (&file_string[35]);
        
        if (ref_mol != atoi (&file_string[53]))
        {
          ref_mol = atoi (&file_string[53]);
          true_label_mol[*num_mol] = ref_mol;
          *num_mol = *num_mol + 1;
        }
        label_mol[*num_atoms] = *num_mol - 1;
        type_atoms[*num_atoms] = j;
        
        *num_atoms = *num_atoms + 1;
      }
  }
  fclose (inp);
  
//   Translation
  tr_num_atoms = *num_atoms;
  for (i=0; i<*num_atoms; i++)
    for (j=0; j<3; j++)
      coords[3*i+j] = not_tr_coords[3*i+j];
  
//   Assign initial value to reference coordinates
  ref_mol = label_mol[0];
  for (i=0; i<3; i++)
    ref[i] = coords[i];
  
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
//         if xyz >= 0.0 A
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
//         if xyz < 0.0 A
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
//         if xyz and xyz >= 0.0 A
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
//         if xyz and xyz < 0.0 A
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
//           if xyz OR xyz >= 0.0
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
//       if x and y and z >= 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] - cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] - cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] >= 0.0) && (ref[2] < 0.0))
//       if x and y >= 0.0 A and z < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] < 0.0) && (ref[2] >= 0.0))
//       if x and z >= 0.0 A and y < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] + cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] - cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] >= 0.0) && (ref[2] >= 0.0))
//       if y and z >= 0.0 A and x < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] - cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] - cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] < 0.0) && (ref[2] >= 0.0))
//       if x and y < 0.0 A and z >= 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] + cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] - cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] >= 0.0) && (ref[2] < 0.0))
//       if x and z < 0.0 A and y >= 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] - cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] + cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] >= 0.0) && (ref[1] < 0.0) && (ref[2] < 0.0))
//       if x >= 0.0 A and y and z < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] - cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] + cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] + cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
    
    if ((ref[0] < 0.0) && (ref[1] < 0.0) && (ref[2] < 0.0))
//       if x and y and z < 0.0 A
    {
      coords[3*tr_num_atoms+0] = not_tr_coords[3*i+0] + cell[0];
      coords[3*tr_num_atoms+1] = not_tr_coords[3*i+1] + cell[1];
      coords[3*tr_num_atoms+2] = not_tr_coords[3*i+2] + cell[2];
      
      label_mol[tr_num_atoms] = label_mol[i];
      type_atoms[tr_num_atoms] = type_atoms[i];
      tr_num_atoms++;
    }
  }
  
  return 0;
}


int main (int argc, char *argv[])
{
//   int i, label_atom[5], label_mol[200000], num_atoms, num_mol, type_atoms[200000];
//   float a[600000], cell[3];
// 
//   for (i=0; i<5; i++)
//     label_atom[i] = 0;
//   label_atom[0] = 1;
//   cell[0] = 34.8616;
//   cell[1] = 34.7930;
//   cell[2] = 34.7925;
// 
//   reading_coords ("oct.001", 1, label_atom, cell, &num_mol, &num_atoms, label_mol, type_atoms, a);
//   
  return 0;
}