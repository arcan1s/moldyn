/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file radf.c
 * Source code of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include <math.h>

#include <mathmech/radf.h>
#include <mathmech/var_types.h>

// pi
#if !defined __USE_BSD && !defined __USE_XOPEN
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* M_PI */
#endif /* __USE_BSD && __USE_XOPEN */


/**
 * @fn search_rdf
 */
int search_rdf (const system_info _system_info, const atom_info *_atom_info, 
                const radf_info _radf_info, int *radf)
{
  float r;
  int i, j, k;
  
/* r                      radius
 */
  
  for (i=0; i<_system_info.num_atoms; i++)
    for (j=0; j<8*_system_info.num_atoms; j++)
      if (((_atom_info[i].type_atoms == 0) && (_atom_info[j].type_atoms == 1)) || 
         ((_atom_info[i].type_atoms == 1) && (_atom_info[j].type_atoms == 0)))
      {
        r = sqrt (pow ((_atom_info[i].coords[0] - _atom_info[j].coords[0]), 2) + 
            pow ((_atom_info[i].coords[1] - _atom_info[j].coords[1]), 2) + 
            pow ((_atom_info[i].coords[2] - _atom_info[j].coords[2]), 2));
        
        if ((r >= _radf_info.r_min) && (r <= _radf_info.r_max))
        {
          k = (r - _radf_info.r_min) / _radf_info.r_step;
          radf[k]++;
        }
      }
  
  return 0;
}


/**
 * @fn search_rdf_centr
 */
int search_rdf_centr (const system_info _system_info, const atom_info *_atom_info, 
                      const radf_info _radf_info, int *radf)
{
  float r, cur_coords[2][3];
  int coef, cur_at, i, j, k, l;
  
/* cur_coords             centered coordinates
 * r                      radius
 * coef                   ==1 if j<_system_info.num_atoms, ==7 if j>=_system_info.num_atoms
 * cur_at                 number of founded atoms
 */
  
  for (i=0; i<_system_info.num_atoms; i++)
    if ((_atom_info[i].type_atoms == 0) || (_atom_info[i].type_atoms == 3))
      for (j=0; j<8*_system_info.num_atoms; j++)
        if (((_atom_info[i].type_atoms == 0) && (_atom_info[j].type_atoms == 3)) || 
           ((_atom_info[i].type_atoms == 3) && (_atom_info[j].type_atoms == 0)))
        {
// set center for i-molecule
          for (l=0; l<3; l++)
            cur_coords[0][l] = _atom_info[i].coords[l];
          cur_at = 1;
          for (k=1; k<6; k++)
            if (_atom_info[i+k].label_mol == _atom_info[i].label_mol)
              if ((_atom_info[i+k].type_atoms == _atom_info[i].type_atoms + 1) || 
                 (_atom_info[i+k].type_atoms == _atom_info[i].type_atoms + 2))
              {
                cur_at++;
                for (l=0; l<3; l++)
                  cur_coords[0][l] += _atom_info[i+k].coords[l];
              }
          if (cur_at == 3)
            for (l=0; l<3; l++)
              cur_coords[0][l] = cur_coords[0][l] / cur_at;
          else
            return 1;
// set center for j-molecule
          for (l=0; l<3; l++)
            cur_coords[1][l] = _atom_info[j].coords[l];
          cur_at = 1;
          if (j < _system_info.num_atoms)
            coef = 1;
          else
            coef = 7;
          for (k=1; k<6; k++)
            if (_atom_info[j+coef*k].label_mol == _atom_info[j].label_mol)
              if ((_atom_info[j+coef*k].type_atoms == _atom_info[j].type_atoms + 1) || 
                 (_atom_info[j+coef*k].type_atoms == _atom_info[j].type_atoms + 2))
              {
                cur_at++;
                for (l=0; l<3; l++)
                  cur_coords[1][l] += _atom_info[j+coef*k].coords[l];
              }
          if (cur_at == 3)
            for (l=0; l<3; l++)
              cur_coords[1][l] = cur_coords[1][l] / cur_at;
          else
            return 1;
          
          r = sqrt (pow ((cur_coords[0][0] - cur_coords[1][0]), 2) + 
              pow ((cur_coords[0][1] - cur_coords[1][1]), 2) + 
              pow ((cur_coords[0][2] - cur_coords[1][2]), 2));
          
          if ((r >= _radf_info.r_min) && (r <= _radf_info.r_max))
          {
            k = (r - _radf_info.r_min) / _radf_info.r_step;
            radf[k]++;
          }
        }
  
  return 0;
}


/**
 * @fn search_radf
 */
int search_radf (const system_info _system_info, const atom_info *_atom_info, 
                 const radf_info _radf_info, int *radf)
{
  float ang, cos_ang, cur_coords[2][3], normal[2][3], r;
  int coef, cur_at, i, j, k, l, n, n_max, plane_index[6];
  
/* ang                    angle
 * cur_coords             centered coordinates
 * normal                 normal to planes
 * r                      radius
 * coef                   ==1 if j<_system_info.num_atoms, ==7 if j>=_system_info.num_atoms
 * cur_at                 number of founded atoms
 * n_max                  range of angles
 * plane_index            atoms forming plane
 */
  
  for (i=0; i<_system_info.num_atoms; i++)
    if ((_atom_info[i].type_atoms == 0) || (_atom_info[i].type_atoms == 3))
      for (j=0; j<8*_system_info.num_atoms; j++)
        if (((_atom_info[i].type_atoms == 0) && (_atom_info[j].type_atoms == 3)) || 
           ((_atom_info[i].type_atoms == 3) && (_atom_info[j].type_atoms == 0)))
        {
// set center for i-molecule
          plane_index[_atom_info[i].type_atoms] = i;
          for (l=0; l<3; l++)
            cur_coords[0][l] = _atom_info[i].coords[l];
          cur_at = 1;
          for (k=1; k<6; k++)
            if (_atom_info[i+k].label_mol == _atom_info[i].label_mol)
              if ((_atom_info[i+k].type_atoms == _atom_info[i].type_atoms + 1) || 
                 (_atom_info[i+k].type_atoms == _atom_info[i].type_atoms + 2))
              {
                cur_at++;
                plane_index[_atom_info[i+k].type_atoms] = i + k;
                for (l=0; l<3; l++)
                  cur_coords[0][l] += _atom_info[i+k].coords[l];
              }
          if (cur_at == 3)
            for (l=0; l<3; l++)
              cur_coords[0][l] = cur_coords[0][l] / cur_at;
          else
            return 1;
// set center for j-molecule
          plane_index[_atom_info[j].type_atoms] = j;
          for (l=0; l<3; l++)
            cur_coords[1][l] = _atom_info[j].coords[l];
          cur_at = 1;
          if (j < _system_info.num_atoms)
            coef = 1;
          else
            coef = 7;
          for (k=1; k<6; k++)
            if (_atom_info[j+coef*k].label_mol == _atom_info[j].label_mol)
              if ((_atom_info[j+coef*k].type_atoms == _atom_info[j].type_atoms + 1) || 
                 (_atom_info[j+coef*k].type_atoms == _atom_info[j].type_atoms + 2))
              {
                cur_at++;
                plane_index[_atom_info[j+coef*k].type_atoms] = j + coef * k;
                for (l=0; l<3; l++)
                  cur_coords[1][l] += _atom_info[j+coef*k].coords[l];
              }
          if (cur_at == 3)
            for (l=0; l<3; l++)
              cur_coords[1][l] = cur_coords[1][l] / cur_at;
          else
            return 1;
          
          r = sqrt (pow ((cur_coords[0][0] - cur_coords[1][0]), 2) + 
              pow ((cur_coords[0][1] - cur_coords[1][1]), 2) + 
              pow ((cur_coords[0][2] - cur_coords[1][2]), 2));
// define planes
          normal[0][0] = (_atom_info[plane_index[1]].coords[1] - _atom_info[plane_index[0]].coords[1]) * 
                         (_atom_info[plane_index[2]].coords[2] - _atom_info[plane_index[0]].coords[2]) - 
                         (_atom_info[plane_index[1]].coords[2] - _atom_info[plane_index[0]].coords[2]) * 
                         (_atom_info[plane_index[2]].coords[1] - _atom_info[plane_index[0]].coords[1]);
          normal[0][1] = (_atom_info[plane_index[1]].coords[2] - _atom_info[plane_index[0]].coords[2]) * 
                         (_atom_info[plane_index[2]].coords[0] - _atom_info[plane_index[0]].coords[0]) - 
                         (_atom_info[plane_index[1]].coords[0] - _atom_info[plane_index[0]].coords[0]) * 
                         (_atom_info[plane_index[2]].coords[2] - _atom_info[plane_index[0]].coords[2]);
          normal[0][2] = (_atom_info[plane_index[1]].coords[0] - _atom_info[plane_index[0]].coords[0]) * 
                         (_atom_info[plane_index[2]].coords[1] - _atom_info[plane_index[0]].coords[1]) - 
                         (_atom_info[plane_index[1]].coords[1] - _atom_info[plane_index[0]].coords[1]) * 
                         (_atom_info[plane_index[2]].coords[0] - _atom_info[plane_index[0]].coords[0]);
          normal[1][0] = (_atom_info[plane_index[4]].coords[1] - _atom_info[plane_index[3]].coords[1]) * 
                         (_atom_info[plane_index[5]].coords[2] - _atom_info[plane_index[3]].coords[2]) - 
                         (_atom_info[plane_index[4]].coords[2] - _atom_info[plane_index[3]].coords[2]) * 
                         (_atom_info[plane_index[5]].coords[1] - _atom_info[plane_index[3]].coords[1]);
          normal[1][1] = (_atom_info[plane_index[4]].coords[2] - _atom_info[plane_index[3]].coords[2]) * 
                         (_atom_info[plane_index[5]].coords[0] - _atom_info[plane_index[3]].coords[0]) - 
                         (_atom_info[plane_index[4]].coords[0] - _atom_info[plane_index[3]].coords[0]) * 
                         (_atom_info[plane_index[5]].coords[2] - _atom_info[plane_index[3]].coords[2]);
          normal[1][2] = (_atom_info[plane_index[4]].coords[0] - _atom_info[plane_index[3]].coords[0]) * 
                         (_atom_info[plane_index[5]].coords[1] - _atom_info[plane_index[3]].coords[1]) - 
                         (_atom_info[plane_index[4]].coords[1] - _atom_info[plane_index[3]].coords[1]) * 
                         (_atom_info[plane_index[5]].coords[0] - _atom_info[plane_index[3]].coords[0]);
          cos_ang = (normal[0][0] * normal[1][0] + normal[0][1] * normal[1][1] + normal[0][2] * normal[1][2]) / 
                    (sqrt (pow ((normal[0][0]), 2) + pow ((normal[0][1]), 2) + pow ((normal[0][2]), 2)) * 
                    sqrt (pow ((normal[1][0]), 2) + pow ((normal[1][1]), 2) + pow ((normal[1][2]), 2)));
          ang = 180 / M_PI * acos (cos_ang);
          if (ang > 90)
            ang = 180 - ang;
          
          n_max = (_radf_info.ang_max - _radf_info.ang_min) / _radf_info.ang_step;
          if ((r >= _radf_info.r_min) && (r <= _radf_info.r_max))
            if ((ang >= _radf_info.ang_min) && (ang <= _radf_info.ang_max))
            {
              k = (r - _radf_info.r_min) / _radf_info.r_step;
              n = (ang - _radf_info.ang_min) / _radf_info.ang_step;
              radf[n_max*k+n]++;
            }
        }
  
  return 0;
}
