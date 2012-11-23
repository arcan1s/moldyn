#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include <math.h>
#include <string.h>


double cell[3], a[10000][3], c[250][30][3];
int num_atom_agl, atom_agl[250], mol[10000], atoms, num_atom[250];
char type_at[10000][4], type[250][30][4];



char conv(int fnumb, int dig_pos)
{
	int s, d, e;
	char digit[10];


	digit[0] = '0';
	digit[1] = '1';
	digit[2] = '2';
	digit[3] = '3';
	digit[4] = '4';
	digit[5] = '5';
	digit[6] = '6';
	digit[7] = '7';
	digit[8] = '8';
	digit[9] = '9';

	if (fnumb >= 100) 
		s = (fnumb - fmod(fnumb, 100)) / 100;
	else 
		s = 0;
	if (fnumb - s*100 >= 10) 
		d = (fnumb - s*100 - fmod(fnumb - s*100, 10))/10;
	else 
		d = 0;
	e = fnumb - s*100 - d*10;

	if (dig_pos == 1) return digit[e];
	if (dig_pos == 2) return digit[d];
	if (dig_pos == 3) return digit[s];
	else return digit[0];
}



void search()
{
	int i, j;


	for (i=0; i<250; i++)
		num_atom[i] = 0;

	for (i=0; i<atoms; i++)
		for (j=0; j<num_atom_agl; j++)
			if (mol[i] == atom_agl[j])
			{
				c[j][num_atom[j]][0] = a[i][0];
				c[j][num_atom[j]][1] = a[i][1];
				c[j][num_atom[j]][2] = a[i][2];
				type[j][num_atom[j]][0] = type_at[i][0];
				type[j][num_atom[j]][1] = type_at[i][1];
				type[j][num_atom[j]][2] = type_at[i][2];
				type[j][num_atom[j]][3] = type_at[i][3];
				num_atom[j]++;
			}
}



void trans()
{
	int i, j, k, imin;
	double x[3], tr[27][30][3], min, leng;


	for (i=1; i<num_atom_agl; i++)
	{
		for (j=0; j<3; j++)
			x[j] = 0;

		for (j=0; j<i; j++)
			for (k=0; k<3; k++)
				x[k] += c[j][0][k];

		for (j=0; j<3; j++)
			x[j] = x[j] / i;

		
		for (k=0; k<num_atom[i]; k++)
		{
			tr[0][k][0] = c[i][k][0];
			tr[0][k][1] = c[i][k][1];
			tr[0][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[1][k][0] = c[i][k][0] + cell[0];
			tr[1][k][1] = c[i][k][1];
			tr[1][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[2][k][0] = c[i][k][0];
			tr[2][k][1] = c[i][k][1] + cell[1];
			tr[2][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[3][k][0] = c[i][k][0];
			tr[3][k][1] = c[i][k][1];
			tr[3][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[4][k][0] = c[i][k][0] - cell[0];
			tr[4][k][1] = c[i][k][1];
			tr[4][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[5][k][0] = c[i][k][0];
			tr[5][k][1] = c[i][k][1] - cell[1];
			tr[5][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[6][k][0] = c[i][k][0];
			tr[6][k][1] = c[i][k][1];
			tr[6][k][2] = c[i][k][2] - cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[7][k][0] = c[i][k][0] + cell[0];
			tr[7][k][1] = c[i][k][1] + cell[1];
			tr[7][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[8][k][0] = c[i][k][0] + cell[0];
			tr[8][k][1] = c[i][k][1];
			tr[8][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[9][k][0] = c[i][k][0];
			tr[9][k][1] = c[i][k][1] + cell[1];
			tr[9][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[10][k][0] = c[i][k][0] - cell[0];
			tr[10][k][1] = c[i][k][1] - cell[1];
			tr[10][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[11][k][0] = c[i][k][0] - cell[0];
			tr[11][k][1] = c[i][k][1];
			tr[11][k][2] = c[i][k][2] - cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[12][k][0] = c[i][k][0];
			tr[12][k][1] = c[i][k][1] - cell[1];
			tr[12][k][2] = c[i][k][2] - cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[13][k][0] = c[i][k][0] + cell[0];
			tr[13][k][1] = c[i][k][1] - cell[1];
			tr[13][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[14][k][0] = c[i][k][0] + cell[0];
			tr[14][k][1] = c[i][k][1];
			tr[14][k][2] = c[i][k][2] - cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[15][k][0] = c[i][k][0] - cell[0];
			tr[15][k][1] = c[i][k][1] + cell[1];
			tr[15][k][2] = c[i][k][2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[16][k][0] = c[i][k][0];
			tr[16][k][1] = c[i][k][1] + cell[1];
			tr[16][k][2] = c[i][k][2] - cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[17][k][0] = c[i][k][0] - cell[0];
			tr[17][k][1] = c[i][k][1];
			tr[17][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[18][k][0] = c[i][k][0];
			tr[18][k][1] = c[i][k][1] - cell[1];
			tr[18][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[19][k][0] = c[i][k][0] + cell[0];
			tr[19][k][1] = c[i][k][1] + cell[1];
			tr[19][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[20][k][0] = c[i][k][0] - cell[0];
			tr[20][k][1] = c[i][k][1] + cell[1];
			tr[20][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[21][k][0] = c[i][k][0] + cell[0];
			tr[21][k][1] = c[i][k][1] - cell[1];
			tr[21][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[22][k][0] = c[i][k][0] + cell[0];
			tr[22][k][1] = c[i][k][1] + cell[1];
			tr[22][k][2] = c[i][k][2] - cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[23][k][0] = c[i][k][0] - cell[0];
			tr[23][k][1] = c[i][k][1] - cell[1];
			tr[23][k][2] = c[i][k][2] + cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[24][k][0] = c[i][k][0] - cell[0];
			tr[24][k][1] = c[i][k][1] + cell[1];
			tr[24][k][2] = c[i][k][2] - cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[25][k][0] = c[i][k][0] + cell[0];
			tr[25][k][1] = c[i][k][1] - cell[1];
			tr[25][k][2] = c[i][k][2] - cell[2];
		}	

		for (k=0; k<num_atom[i]; k++)
		{
			tr[26][k][0] = c[i][k][0] - cell[0];
			tr[26][k][1] = c[i][k][1] - cell[1];
			tr[26][k][2] = c[i][k][2] - cell[2];
		}


		imin = 0;
		min = sqrt ((tr[0][0][0] - x[0])*(tr[0][0][0] - x[0]) + (tr[0][0][1] - x[1])*(tr[0][0][1] - x[1]) + (tr[0][0][2] - x[2])*(tr[0][0][2] - x[2]));
		for (j=1; j<27; j++)
		{
			leng = sqrt ((tr[j][0][0] - x[0])*(tr[j][0][0] - x[0]) + (tr[j][0][1] - x[1])*(tr[j][0][1] - x[1]) + (tr[j][0][2] - x[2])*(tr[j][0][2] - x[2]));

			if (leng < min)
			{
				min = leng;
				imin = j;
			}
		}

		
		for (k=0; k<num_atom[i]; k++)
		{
			for (j=0; j<3; j++)
			{
				c[i][k][j] = tr[imin][k][j];
			}
		}
	}
}



void coord_data(FILE *fs)
{
	int i, j, atom_num, atom_type;
	double x, y, z;
	char q[256];
	

	fscanf (fs, "%i", &atoms);
	for (i=0; i<atoms; i++)
	{
		fscanf (fs, "%i", &atom_num);
		for (j=0; j<4; j++) 
			fscanf (fs, "%c", &type_at[i][j]);
		fscanf (fs, "%lf", &x);
		fscanf (fs, "%lf", &y);
		fscanf (fs, "%lf", &z);
		fscanf (fs, "%i", &atom_type);
		fscanf (fs, "%i", &mol[i]);

		fgets (q, 256, fs);

		a[i][0] = x;
		a[i][1] = y;
		a[i][2] = z;
	}

	search();
}



void aglom(FILE *fin)
{
	int i;
	char q[256];


	fscanf (fin, "%i", &num_atom_agl); 
	fgets (q, 256, fin);
	for (i=0; i<num_atom_agl; i++)
	{
		fscanf (fin, "%i", &atom_agl[i]); 
		fgets (q, 256, fin);
	}
}



void output (FILE *fout)
{
	int i, k, inp;


	inp = 1;
	for (i=0; i<num_atom_agl; i++)
		for (k=0; k<num_atom[i]; k++)
		{
			fprintf (fout, "ATOM  %5i  %c%c  MOL %5i    %8.3f%8.3f%8.3f\n", inp, type[i][k][2], type[i][k][3], i+1, c[i][k][0], c[i][k][1], c[i][k][2]);

			inp++;
		}
}



void main(void)
{
	char name[128], coord_name[128], out_name[128], q[128];
	int i, k, agl;
	FILE *f;
	FILE *inp;
	FILE *coord;
	FILE *out;

	
	f=fopen ("input_agl.dat", "r");
	for (i=0; i<10; i++)
		fscanf (f, "%c", &q[i]);
	fscanf (f, "%s", &name);
	for (i=0; i<24; i++)
		fscanf (f, "%c", &q[i]);
	fscanf (f, "%i", &agl);
	for (i=0; i<15; i++)
		fscanf (f, "%c", &q[i]);
	for (i=0; i<3; i++)
		fscanf (f, "%lf", &cell[i]);
	fgets (q, 128, f);
	for (i=0; i<7; i++)
		fscanf (f, "%c", &q[i]);
	fscanf (f, "%s", &out_name);	
	fclose (f);
	

	k = strlen (out_name);
	out_name[k] = out_name[k-4];
	out_name[k+1] = out_name[k-3];
	out_name[k+2] = out_name[k-2];
	out_name[k+3] = out_name[k-1];
	out_name[k+4] = '\0';
	inp=fopen (name, "r");
	for (i=0; i<agl; i++)
	{
		fscanf (inp, "%s", &coord_name);
		aglom (inp);


		coord=fopen (coord_name, "r");
		coord_data (coord);
		fclose (coord);


		trans();


		out_name[k-4] = '_';
		out_name[k-3] = conv (i+1, 3);
		out_name[k-2] = conv (i+1, 2);
		out_name[k-1] = conv (i+1, 1);
		out=fopen (out_name, "w+");
		output (out);
		fclose (out);
	}
	fclose (inp);
}