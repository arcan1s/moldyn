/**
 * @file
 */

#include <math.h>

// pi
#if !defined __USE_BSD && !defined __USE_XOPEN
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* __USE_BSD && __USE_XOPEN */
#endif /* M_PI */


/**
 * @fn search_rdf
 */
int search_rdf (const int num_atoms, const int *type_atoms, const int *label_mol, 
                const float *coords, const double r_min, const double r_max, 
                const double r_step, int *radf)
/**
 * @brief function that searchs molecule for rdf massive
 * @code
 * search_rdf (num_atoms, type_atoms, label_mol, coords, r_min, r_max, r_step, radf);
 * @endcode
 * 
 * @param num_atoms       number of atoms
 * @param type_atoms      massive of atom types
 * @param label_mol       massive of numbers of molecule for atoms
 * @param coords          massive of coordinates
 * @param r_min           minimal radius
 * @param r_max           maximal radius
 * @param r_step          radius step
 * @param radf            not normed RDF
 * 
 * @return 0              - exit without errors
 */
{
  float r;
  int i, j, k;
  
/* r                      radius
 */
  
  for (i=0; i<num_atoms; i++)
    for (j=0; j<8*num_atoms; j++)
      if (((type_atoms[i] == 0) && (type_atoms[j] == 1)) || 
         ((type_atoms[i] == 1) && (type_atoms[j] == 0)))
      {
        r = sqrt (pow ((coords[3*i+0] - coords[3*j+0]), 2) + 
            pow ((coords[3*i+1] - coords[3*j+1]), 2) + 
            pow ((coords[3*i+2] - coords[3*j+2]), 2));
        
        if ((r >= r_min) && (r <= r_max))
        {
          k = (r - r_min) / r_step;
          radf[k]++;
        }
      }
  
  return 0;
}


/**
 * @fn search_rdf_centr
 */
int search_rdf_centr (const int num_atoms, const int *type_atoms, const int *label_mol, 
                      const float *coords, const double r_min, const double r_max, 
                      const double r_step, int *radf)
/**
 * @brief function that searchs molecule for rdf massive by centered coordinates
 * @code
 * search_rdf_centr (num_atoms, type_atoms, label_mol, coords, r_min, r_max, r_step, 
 *                   radf);
 * @endcode
 * 
 * @param num_atoms       number of atoms
 * @param type_atoms      massive of atom types
 * @param label_mol       massive of numbers of molecule for atoms
 * @param coords          massive of coordinates
 * @param r_min           minimal radius
 * @param r_max           maximal radius
 * @param r_step          radius step
 * @param radf            not normed RDF
 * 
 * @return 0              - exit without errors
 * @return 1              - error in set center (missing atoms)
 */
{
  float r, cur_coords[2][3];
  int coef, cur_at, i, j, k, l;
  
/* cur_coords             centered coordinates
 * r                      radius
 * coef                   ==1 if j<num_atoms, ==7 if j>=num_atoms
 * cur_at                 number of founded atoms
 */
  
  for (i=0; i<num_atoms; i++)
    if ((type_atoms[i] == 0) || (type_atoms[i] == 3))
      for (j=0; j<8*num_atoms; j++)
        if (((type_atoms[i] == 0) && (type_atoms[j] == 3)) || 
           ((type_atoms[i] == 3) && (type_atoms[j] == 0)))
        {
// set center for i-molecule
          for (l=0; l<3; l++)
            cur_coords[0][l] = coords[3*i+l];
          cur_at = 1;
          for (k=1; k<6; k++)
            if (label_mol[i+k] == label_mol[i])
              if ((type_atoms[i+k] == type_atoms[i] + 1) || 
                 (type_atoms[i+k] == type_atoms[i] + 2))
              {
                cur_at++;
                for (l=0; l<3; l++)
                  cur_coords[0][l] += coords[3*(i+k)+l];
              }
          if (cur_at == 3)
            for (l=0; l<3; l++)
              cur_coords[0][l] = cur_coords[0][l] / cur_at;
          else
            return 1;
// set center for j-molecule
          for (l=0; l<3; l++)
            cur_coords[1][l] = coords[3*j+l];
          cur_at = 1;
          if (j < num_atoms)
            coef = 1;
          else
            coef = 7;
          for (k=1; k<6; k++)
            if (label_mol[j+coef*k] == label_mol[j])
              if ((type_atoms[j+coef*k] == type_atoms[j] + 1) || 
                 (type_atoms[j+coef*k] == type_atoms[j] + 2))
              {
                cur_at++;
                for (l=0; l<3; l++)
                  cur_coords[1][l] += coords[3*(j+coef*k)+l];
              }
          if (cur_at == 3)
            for (l=0; l<3; l++)
              cur_coords[1][l] = cur_coords[1][l] / cur_at;
          else
            return 1;
          
          r = sqrt (pow ((cur_coords[0][0] - cur_coords[1][0]), 2) + 
              pow ((cur_coords[0][1] - cur_coords[1][1]), 2) + 
              pow ((cur_coords[0][2] - cur_coords[1][2]), 2));
          
          if ((r >= r_min) && (r <= r_max))
          {
            k = (r - r_min) / r_step;
            radf[k]++;
          }
        }
  
  return 0;
}


/**
 * @fn search_radf
 */
int search_radf (const int num_atoms, const int *type_atoms, const int *label_mol, 
                 const float *coords, const double r_min, const double r_max, 
                 const double r_step, const double ang_min, const double ang_max, 
                 const double ang_step, int *radf)
/**
 * @brief function that searchs molecule for radf massive
 * @code
 * search_radf (num_atoms, type_atoms, label_mol, coords, r_min, r_max, r_step, 
 *              ang_min, ang_max, ang_step, radf);
 * @endcode
 * 
 * @param num_atoms       number of atoms
 * @param type_atoms      massive of atom types
 * @param label_mol       massive of numbers of molecule for atoms
 * @param coords          massive of coordinates
 * @param r_min           minimal radius
 * @param r_max           maximal radius
 * @param r_step          radius step
 * @param ang_min         minimal angle
 * @param ang_max         maximal angle
 * @param ang_step        anlge step
 * @param radf            not normed RADF
 * 
 * @return 0              - exit without errors
 * @return 1              - error in set center (missing atoms)
 */
{
  float ang, cos_ang, cur_coords[2][3], normal[2][3], r;
  int coef, cur_at, i, j, k, l, n, n_max, plane_index[6];
  
/* ang                    angle
 * cur_coords             centered coordinates
 * normal                 normal to planes
 * r                      radius
 * coef                   ==1 if j<num_atoms, ==7 if j>=num_atoms
 * cur_at                 number of founded atoms
 * n_max                  range of angles
 * plane_index            atoms forming plane
 */
  
  for (i=0; i<num_atoms; i++)
    if ((type_atoms[i] == 0) || (type_atoms[i] == 3))
      for (j=0; j<8*num_atoms; j++)
        if (((type_atoms[i] == 0) && (type_atoms[j] == 3)) || 
           ((type_atoms[i] == 3) && (type_atoms[j] == 0)))
        {
// set center for i-molecule
          plane_index[type_atoms[i]] = i;
          for (l=0; l<3; l++)
            cur_coords[0][l] = coords[3*i+l];
          cur_at = 1;
          for (k=1; k<6; k++)
            if (label_mol[i+k] == label_mol[i])
              if ((type_atoms[i+k] == type_atoms[i] + 1) || 
                 (type_atoms[i+k] == type_atoms[i] + 2))
              {
                cur_at++;
                plane_index[type_atoms[i+k]] = i + k;
                for (l=0; l<3; l++)
                  cur_coords[0][l] += coords[3*(i+k)+l];
              }
          if (cur_at == 3)
            for (l=0; l<3; l++)
              cur_coords[0][l] = cur_coords[0][l] / cur_at;
          else
            return 1;
// set center for j-molecule
          plane_index[type_atoms[j]] = j;
          for (l=0; l<3; l++)
            cur_coords[1][l] = coords[3*j+l];
          cur_at = 1;
          if (j < num_atoms)
            coef = 1;
          else
            coef = 7;
          for (k=1; k<6; k++)
            if (label_mol[j+coef*k] == label_mol[j])
              if ((type_atoms[j+coef*k] == type_atoms[j] + 1) || 
                 (type_atoms[j+coef*k] == type_atoms[j] + 2))
              {
                cur_at++;
                plane_index[type_atoms[j+coef*k]] = j + coef * k;
                for (l=0; l<3; l++)
                  cur_coords[1][l] += coords[3*(j+coef*k)+l];
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
          normal[0][0] = (coords[3*plane_index[1]+1] - coords[3*plane_index[0]+1]) * 
                         (coords[3*plane_index[2]+2] - coords[3*plane_index[0]+2]) - 
                         (coords[3*plane_index[1]+2] - coords[3*plane_index[0]+2]) * 
                         (coords[3*plane_index[2]+1] - coords[3*plane_index[0]+1]);
          normal[0][1] = (coords[3*plane_index[1]+2] - coords[3*plane_index[0]+2]) * 
                         (coords[3*plane_index[2]+0] - coords[3*plane_index[0]+0]) - 
                         (coords[3*plane_index[1]+0] - coords[3*plane_index[0]+0]) * 
                         (coords[3*plane_index[2]+2] - coords[3*plane_index[0]+2]);
          normal[0][2] = (coords[3*plane_index[1]+0] - coords[3*plane_index[0]+0]) * 
                         (coords[3*plane_index[2]+1] - coords[3*plane_index[0]+1]) - 
                         (coords[3*plane_index[1]+1] - coords[3*plane_index[0]+1]) * 
                         (coords[3*plane_index[2]+0] - coords[3*plane_index[0]+0]);
          normal[1][0] = (coords[3*plane_index[4]+1] - coords[3*plane_index[3]+1]) * 
                         (coords[3*plane_index[5]+2] - coords[3*plane_index[3]+2]) - 
                         (coords[3*plane_index[4]+2] - coords[3*plane_index[3]+2]) * 
                         (coords[3*plane_index[5]+1] - coords[3*plane_index[3]+1]);
          normal[1][1] = (coords[3*plane_index[4]+2] - coords[3*plane_index[3]+2]) * 
                         (coords[3*plane_index[5]+0] - coords[3*plane_index[3]+0]) - 
                         (coords[3*plane_index[4]+0] - coords[3*plane_index[3]+0]) * 
                         (coords[3*plane_index[5]+2] - coords[3*plane_index[3]+2]);
          normal[1][2] = (coords[3*plane_index[4]+0] - coords[3*plane_index[3]+0]) * 
                         (coords[3*plane_index[5]+1] - coords[3*plane_index[3]+1]) - 
                         (coords[3*plane_index[4]+1] - coords[3*plane_index[3]+1]) * 
                         (coords[3*plane_index[5]+0] - coords[3*plane_index[3]+0]);
          cos_ang = (normal[0][0] * normal[1][0] + normal[0][1] * normal[1][1] + normal[0][2] * normal[1][2]) / 
                    (sqrt (pow ((normal[0][0]), 2) + pow ((normal[0][1]), 2) + pow ((normal[0][2]), 2)) * 
                    sqrt (pow ((normal[1][0]), 2) + pow ((normal[1][1]), 2) + pow ((normal[1][2]), 2)));
          ang = 180 / M_PI * acos (cos_ang);
          if (ang > 90)
            ang = 180 - ang;
          
          n_max = (ang_max - ang_min) / ang_step;
          if ((r >= r_min) && (r <= r_max))
            if ((ang >= ang_min) && (ang <= ang_max))
            {
              k = (r - r_min) / r_step;
              n = (ang - ang_min) / ang_step;
              radf[n_max*k+n]++;
            }
        }
  
  return 0;
}
