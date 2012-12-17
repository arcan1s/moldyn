#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void main(int argc, char *argv[])
{
  int i, j, n_bonds, n_angles, num[2];
  char q[256], label[512][4], type[4];
  double charge;
  FILE *inp, *out;


  if (argc == 1)
  {
    printf ("Error: Parametrs is not enable!\n");
    printf ("Usage --help or -h for help\n");
    exit(0);
  }
  if ((argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == 'h' && argv[1][3] == 'e' && argv[1][4] == 'l', argv[1][5] == 'p') || (argv[1][0] == '-' && argv[1][1] == 'h'))
  {
    printf ("mol2rtp convert *.mol2 file in GROMACS topology file *.rtp\n");
    printf ("NOTE: You must edit MM atom type in *.rtp file\n");
    printf ("Usage:    mol2rtp [MOL2.FILE] [RTP.FILE]\n");
    printf ("Evgeniy Alexeev aka arcanis\n");
    printf ("email: esalexeev@gmail.com\n");
    exit(0);
  }
  else
    if (argc == 2)
    {
      printf ("Error: Parametrs is not enable!\n");
      printf ("Usage --help or -h for help\n");
      exit(0);
    }


  printf ("mol2rtp V.1.0\n");
  inp = fopen (argv[1], "r+");
  if (inp == NULL)
  {
    printf ("File %s is not found!\n", argv[1]);
    exit(0);
  }
  out = fopen (argv[2], "w+");


  fgets (q, 255, inp);
  fgets (q, 255, inp);
  fscanf (inp, "%i", &n_bonds);
  fscanf (inp, "%i", &n_angles);
  for (i=0; i<5; i++)
    fgets (q, 255, inp);


  printf ("Enter molecule name: ");
  scanf ("%s", q);
  fprintf (out, "[ %s ]\n [ atoms ]\n", q);
  for (i=0; i<n_bonds; i++)
  {
    fgets( q, 255, inp);
    charge = atof (&q[69]);
    for (j=0; j<4; j++)
    {
      type[j] = q[j+47];
      label[i][j] = q[j+8];
    }

    fprintf (out, "  %c%c%c%c   %c%c%c%c   %5.2f%5i\n", label[i][0], label[i][1], label[i][2], label[i][3], type[0], type[1], type[2], type[3], charge, i);
  }


  fprintf (out, " [ bonds ]\n");
  fgets (q, 255, inp);
  for (i=0; i<n_angles; i++)
  {
    fscanf (inp, "%i", &j);
    fscanf (inp, "%i", &num[0]);
    fscanf (inp, "%i", &num[1]);
    fscanf (inp, "%i", &j);

    fprintf (out, "  %c%c%c%c    %c%c%c%c\n", label[num[0]-1][0], label[num[0]-1][1], label[num[0]-1][2], label[num[0]-1][3], label[num[1]-1][0], label[num[1]-1][1], label[num[1]-1][2], label[num[1]-1][3]);
  }


  fclose (inp);
  fclose (out);
}
