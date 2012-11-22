#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include <math.h>
#include <string.h>



int type_int, mol_atom_arr[2], num_agl_atom, step, mol[1000], label[8000], agl_all[350], all_bond_stat[500];
int num_mol, num_mol_ext, label_mol[8000][6][2], bond_array[1000][1000], cycle, linear;
double cell_param[3], bond_param[2], a[480000][3][2];
char name[128];



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



void input_data(FILE *fs)
{
	char q[64];
	int i, j, k, l, m, n, inp[2], o;
	int atoms, number, atom_t, molecule, numb[2];
	double x, y, z; 


	l = 0;
	numb[0] = 0;
	numb[1] = 0;
	for (i=0; i<8000; i++)
		for (j=0; j<6; j++)
			for (k=0; k<type_int; k++)
				label_mol[i][j][k] = 10000;


	fscanf (fs, "%i", &atoms);
	for (i=0; i<atoms; i++)
	{
		fscanf (fs, "%i", &number);
		for (j=0; j<4; j++) 
			fscanf (fs, "%c", &q[j]);
		fscanf (fs, "%lf", &x);
		fscanf (fs, "%lf", &y);
		fscanf (fs, "%lf", &z);
		fscanf (fs, "%i", &atom_t);
		fscanf (fs, "%i", &molecule);
		fgets (q, 64, fs);

		for (j=0; j<type_int; j++)
			if (atom_t == mol_atom_arr[j])
			{
				a[numb[j]][0][j] = x;
				a[numb[j]][1][j] = y;
				a[numb[j]][2][j] = z;	
				if ((molecule != mol[l]) && (label_mol[0][0][j] != 10000))
					l++;
				mol[l] = molecule;
				label[l] = l;
				k = 0;
				while (label_mol[l][k][j] != 10000)
					k++;
				label_mol[l][k][j] = numb[j];
				numb[j]++;
			}
	}
	

	num_mol = l + 1;
	num_mol_ext = num_mol;
	inp[0] = numb[0];
	inp[1] = numb[1];

	for (i=0; i<num_mol; i++)
	{
		for (j=0; j<3; j++)
		{
			if (a[label_mol[i][0][0]][j][0] > 0)
			{
				for (k=0; k<type_int; k++)
				{
					l = 0;
					while (label_mol[i][l][k] != 10000)
					{
						for (m=0; m<3; m++)
							if (m == j)
								a[inp[k]][m][k] = a[label_mol[i][l][k]][m][k] - cell_param[m];
							else
								a[inp[k]][m][k] = a[label_mol[i][l][k]][m][k];

						o = 0;
						while (label_mol[num_mol_ext][o][k] != 10000)
							o++;
						label_mol[num_mol_ext][o][k] = inp[k];
						inp[k]++;

						l++;
					}
				}
				label[num_mol_ext] = label[i];
				num_mol_ext++;
			}

			if (a[label_mol[i][0][0]][j][0] < 0)
			{
				for (k=0; k<type_int; k++)
				{
					l = 0;
					while (label_mol[i][l][k] != 10000)
					{
						for (m=0; m<3; m++)
							if (m == j)
								a[inp[k]][m][k] = a[label_mol[i][l][k]][m][k] + cell_param[m];
							else
								a[inp[k]][m][k] = a[label_mol[i][l][k]][m][k];

						o = 0;
						while (label_mol[num_mol_ext][o][k] != 10000)
							o++;
						label_mol[num_mol_ext][o][k] = inp[k];
						inp[k]++;

						l++;
					}
				}
				label[num_mol_ext] = label[i];
				num_mol_ext++;
			}
		}


		for (j=0; j<3; j++)
		{
			for (k=j+1; k<3; k++)
			{
				if ((a[label_mol[i][0][0]][j][0] > 0) && (a[label_mol[i][0][0]][k][0] > 0))
				{
					for (l=0; l<type_int; l++)
					{
						m = 0;
						while (label_mol[i][m][l] != 10000)
						{
							for (n=0; n<3; n++)
							{
								if (n == j)
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l] - cell_param[n];
								if (n == k)
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l] - cell_param[n];
								if ((n != j) && (n != k))
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l];
							}
							o = 0;
							while (label_mol[num_mol_ext][o][l] != 10000)
								o++;
							label_mol[num_mol_ext][o][l] = inp[l];
							inp[l]++;

							m++;
						}
					}
					label[num_mol_ext] = label[i];
					num_mol_ext++;
				}

				if ((a[label_mol[i][0][0]][j][0] < 0) && (a[label_mol[i][0][0]][k][0] < 0))
				{
					for (l=0; l<type_int; l++)
					{
						m = 0;
						while (label_mol[i][m][l] != 10000)
						{
							for (n=0; n<3; n++)
							{
								if (n == j)
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l] + cell_param[n];
								if (n == k)
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l] + cell_param[n];
								if ((n != j) && (n != k))
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l];
							}
							o = 0;
							while (label_mol[num_mol_ext][o][l] != 10000)
								o++;
							label_mol[num_mol_ext][o][l] = inp[l];
							inp[l]++;

							m++;
						}
					}
					label[num_mol_ext] = label[i];
					num_mol_ext++;
				}
			}

			for (k=0; k<3; k++)
				if ((a[label_mol[i][0][0]][j][0] < 0) && (a[label_mol[i][0][0]][k][0] > 0))
				{
					for (l=0; l<type_int; l++)
					{
						m = 0;
						while (label_mol[i][m][l] != 10000)
						{
							for (n=0; n<3; n++)
							{
								if (n == j)
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l] + cell_param[n];
								if (n == k)
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l] - cell_param[n];
								if ((n != j) && (n != k))
									a[inp[l]][n][l] = a[label_mol[i][m][l]][n][l];
							}
							o = 0;
							while (label_mol[num_mol_ext][o][l] != 10000)
								o++;
							label_mol[num_mol_ext][o][l] = inp[l];
							inp[l]++;

							m++;
						}
					}
					label[num_mol_ext] = label[i];
					num_mol_ext++;
				}

		}


		if ((a[label_mol[i][0][0]][0][0] > 0) && (a[label_mol[i][0][0]][1][0] > 0) && (a[label_mol[i][0][0]][2][0] > 0))
		{
			for (j=0; j<type_int; j++)
			{
				k = 0;
				while (label_mol[i][k][j] != 10000)
				{
					a[inp[j]][0][j] = a[label_mol[i][k][j]][0][j] - cell_param[0];
					a[inp[j]][1][j] = a[label_mol[i][k][j]][1][j] - cell_param[1];
					a[inp[j]][2][j] = a[label_mol[i][k][j]][2][j] - cell_param[2];

					o = 0;
					while (label_mol[num_mol_ext][o][j] != 10000)
						o++;
					label_mol[num_mol_ext][o][j] = inp[j];
					inp[j]++;

					k++;
				}
			}
			label[num_mol_ext] = label[i];
			num_mol_ext++;
		}

		if ((a[label_mol[i][0][0]][0][0] > 0) && (a[label_mol[i][0][0]][1][0] > 0) && (a[label_mol[i][0][0]][2][0] < 0))
		{
			for (j=0; j<type_int; j++)
			{
				k = 0;
				while (label_mol[i][k][j] != 10000)
				{
					a[inp[j]][0][j] = a[label_mol[i][k][j]][0][j] - cell_param[0];
					a[inp[j]][1][j] = a[label_mol[i][k][j]][1][j] - cell_param[1];
					a[inp[j]][2][j] = a[label_mol[i][k][j]][2][j] + cell_param[2];

					o = 0;
					while (label_mol[num_mol_ext][o][j] != 10000)
						o++;
					label_mol[num_mol_ext][o][j] = inp[j];
					inp[j]++;

					k++;
				}
			}
			label[num_mol_ext] = label[i];
			num_mol_ext++;
		}

		if ((a[label_mol[i][0][0]][0][0] > 0) && (a[label_mol[i][0][0]][1][0] < 0) && (a[label_mol[i][0][0]][2][0] > 0))
		{
			for (j=0; j<type_int; j++)
			{
				k = 0;
				while (label_mol[i][k][j] != 10000)
				{
					a[inp[j]][0][j] = a[label_mol[i][k][j]][0][j] - cell_param[0];
					a[inp[j]][1][j] = a[label_mol[i][k][j]][1][j] + cell_param[1];
					a[inp[j]][2][j] = a[label_mol[i][k][j]][2][j] - cell_param[2];

					o = 0;
					while (label_mol[num_mol_ext][o][j] != 10000)
						o++;
					label_mol[num_mol_ext][o][j] = inp[j];
					inp[j]++;

					k++;
				}
			}
			label[num_mol_ext] = label[i];
			num_mol_ext++;
		}

		if ((a[label_mol[i][0][0]][0][0] < 0) && (a[label_mol[i][0][0]][1][0] > 0) && (a[label_mol[i][0][0]][2][0] > 0))
		{
			for (j=0; j<type_int; j++)
			{
				k = 0;
				while (label_mol[i][k][j] != 10000)
				{
					a[inp[j]][0][j] = a[label_mol[i][k][j]][0][j] + cell_param[0];
					a[inp[j]][1][j] = a[label_mol[i][k][j]][1][j] - cell_param[1];
					a[inp[j]][2][j] = a[label_mol[i][k][j]][2][j] - cell_param[2];

					o = 0;
					while (label_mol[num_mol_ext][o][j] != 10000)
						o++;
					label_mol[num_mol_ext][o][j] = inp[j];
					inp[j]++;

					k++;
				}
			}
			label[num_mol_ext] = label[i];
			num_mol_ext++;
		}

		if ((a[label_mol[i][0][0]][0][0] < 0) && (a[label_mol[i][0][0]][1][0] < 0) && (a[label_mol[i][0][0]][2][0] > 0))
		{
			for (j=0; j<type_int; j++)
			{
				k = 0;
				while (label_mol[i][k][j] != 10000)
				{
					a[inp[j]][0][j] = a[label_mol[i][k][j]][0][j] + cell_param[0];
					a[inp[j]][1][j] = a[label_mol[i][k][j]][1][j] + cell_param[1];
					a[inp[j]][2][j] = a[label_mol[i][k][j]][2][j] - cell_param[2];

					o = 0;
					while (label_mol[num_mol_ext][o][j] != 10000)
						o++;
					label_mol[num_mol_ext][o][j] = inp[j];
					inp[j]++;

					k++;
				}
			}
			label[num_mol_ext] = label[i];
			num_mol_ext++;
		}

		if ((a[label_mol[i][0][0]][0][0] < 0) && (a[label_mol[i][0][0]][1][0] > 0) && (a[label_mol[i][0][0]][2][0] < 0))
		{
			for (j=0; j<type_int; j++)
			{
				k = 0;
				while (label_mol[i][k][j] != 10000)
				{
					a[inp[j]][0][j] = a[label_mol[i][k][j]][0][j] + cell_param[0];
					a[inp[j]][1][j] = a[label_mol[i][k][j]][1][j] - cell_param[1];
					a[inp[j]][2][j] = a[label_mol[i][k][j]][2][j] + cell_param[2];

					o = 0;
					while (label_mol[num_mol_ext][o][j] != 10000)
						o++;
					label_mol[num_mol_ext][o][j] = inp[j];
					inp[j]++;

					k++;
				}
			}
			label[num_mol_ext] = label[i];
			num_mol_ext++;
		}

		if ((a[label_mol[i][0][0]][0][0] > 0) && (a[label_mol[i][0][0]][1][0] < 0) && (a[label_mol[i][0][0]][2][0] < 0))
		{
			for (j=0; j<type_int; j++)
			{
				k = 0;
				while (label_mol[i][k][j] != 10000)
				{
					a[inp[j]][0][j] = a[label_mol[i][k][j]][0][j] - cell_param[0];
					a[inp[j]][1][j] = a[label_mol[i][k][j]][1][j] + cell_param[1];
					a[inp[j]][2][j] = a[label_mol[i][k][j]][2][j] + cell_param[2];

					o = 0;
					while (label_mol[num_mol_ext][o][j] != 10000)
						o++;
					label_mol[num_mol_ext][o][j] = inp[j];
					inp[j]++;

					k++;
				}
			}
			label[num_mol_ext] = label[i];
			num_mol_ext++;
		}

		if ((a[label_mol[i][0][0]][0][0] < 0) && (a[label_mol[i][0][0]][1][0] < 0) && (a[label_mol[i][0][0]][2][0] < 0))
		{
			for (j=0; j<type_int; j++)
			{
				k = 0;
				while (label_mol[i][k][j] != 10000)
				{
					a[inp[j]][0][j] = a[label_mol[i][k][j]][0][j] + cell_param[0];
					a[inp[j]][1][j] = a[label_mol[i][k][j]][1][j] + cell_param[1];
					a[inp[j]][2][j] = a[label_mol[i][k][j]][2][j] + cell_param[2];

					o = 0;
					while (label_mol[num_mol_ext][o][j] != 10000)
						o++;
					label_mol[num_mol_ext][o][j] = inp[j];
					inp[j]++;

					k++;
				}
			}
			label[num_mol_ext] = label[i];
			num_mol_ext++;
		}
	}
}



void stat(FILE *fo, int chs)
{
	int i, j, h, k, l, p, x, y;
	int num_bond[1000], bond[1000][20], bin[1000], label_bond[650][350], agl[350], label_num[650];
	double leng, min, min00;
	char q[3];


	for (i=0; i<650; i++)
	{
		for (j=0; j<350; j++)
			label_bond[i][j] = 0;
		label_num[i] = 0;
	}
	for (i=0; i<350; i++)						
		agl[i] = 0;
	for (i=0; i<1000; i++)
	{
		for (j=0; j<20; j++)
			bond[i][j] = 0;
		num_bond[i] = 0;
	}


	fprintf (fo, "\nFILE:     %s\n", name);
	switch (type_int)
	{
	case 1:
		for (i=0; i<num_mol_ext; i++)
			for (j=i+1; j<num_mol_ext; j++)
			{
				min = sqrt ((a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][0]][0][0])*(a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][0]][0][0]) + (a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][0]][1][0])*(a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][0]][1][0]) + (a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][0]][2][0])*(a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][0]][2][0]));
				h = 0;
				while (label_mol[i][h][0] != 10000)
				{
					k = 0;
					while (label_mol[j][k][0] != 10000)
					{
						leng = sqrt ((a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][0]][0][0])*(a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][0]][0][0]) + (a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][0]][1][0])*(a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][0]][1][0]) + (a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][0]][2][0])*(a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][0]][2][0]));
						if (leng < min)
							min = leng;
						k++;
					}
					h++;
				}

				if (min < bond_param[0])
				{
					k = 1;
					for (l=0; l<num_bond[label[i]]; l++)
						if (bond[label[i]][l] == label[j])
							k = 0;

					if (k == 1)
					{
						bond[label[i]][num_bond[label[i]]] = label[j];
						num_bond[label[i]]++;
						bond[label[j]][num_bond[label[j]]] = label[i];
						num_bond[label[j]]++;

						if (chs > 0)
						{
							bond_array[label[i]][label[j]] = (100*min - fmod(100*min, 1));
							bond_array[label[j]][label[i]] = (100*min - fmod(100*min, 1));
						}
					}
				}
			}
	break;
	
	case 2:
		for (i=0; i<num_mol_ext; i++)
			for (j=i+1; j<num_mol_ext; j++)
			{
				min = sqrt ((a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][0]][0][0])*(a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][0]][0][0]) + (a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][0]][1][0])*(a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][0]][1][0]) + (a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][0]][2][0])*(a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][0]][2][0]));
				h = 0;
				while (label_mol[i][h][0] != 10000)
				{
					k = 0;
					while (label_mol[j][k][0] != 10000)
					{
						leng = sqrt ((a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][0]][0][0])*(a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][0]][0][0]) + (a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][0]][1][0])*(a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][0]][1][0]) + (a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][0]][2][0])*(a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][0]][2][0]));
						if (leng < min)
							min = leng;
						k++;
					}
					h++;
				}

				if (min < bond_param[0])
				{
					min00 = min;
					min = sqrt ((a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][1]][0][1])*(a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][1]][0][1]) + (a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][1]][1][1])*(a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][1]][1][1]) + (a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][1]][2][1])*(a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][1]][2][1]));
					h = 0;
					while (label_mol[i][h][0] != 10000)
					{
						k = 0;
						while (label_mol[j][k][1] != 10000)
						{
							leng = sqrt ((a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][1]][0][1])*(a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][1]][0][1]) + (a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][1]][1][1])*(a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][1]][1][1]) + (a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][1]][2][1])*(a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][1]][2][1]));
							if (leng < min)
								min = leng;
							k++;
						}
						h++;
					}

					if (min < bond_param[1])
					{
						k = 1;
						for (l=0; l<num_bond[label[i]]; l++)
							if (bond[label[i]][l] == label[j])
								k = 0;

						if (k == 1)
						{
							bond[label[i]][num_bond[label[i]]] = label[j];
							num_bond[label[i]]++;
							bond[label[j]][num_bond[label[j]]] = label[i];
							num_bond[label[j]]++;

							if (chs > 0)
							{
								bond_array[label[i]][label[j]] = (100*min00 - fmod(100*min00, 1));
								bond_array[label[j]][label[i]] = (100*min00 - fmod(100*min00, 1));
							}
						}
					}
					else
					{
						min = sqrt ((a[label_mol[i][0][1]][0][1]-a[label_mol[j][0][0]][0][0])*(a[label_mol[i][0][1]][0][1]-a[label_mol[j][0][0]][0][0]) + (a[label_mol[i][0][1]][1][1]-a[label_mol[j][0][0]][1][0])*(a[label_mol[i][0][1]][1][1]-a[label_mol[j][0][0]][1][0]) + (a[label_mol[i][0][1]][2][1]-a[label_mol[j][0][0]][2][0])*(a[label_mol[i][0][1]][2][1]-a[label_mol[j][0][0]][2][0]));
						h = 0;
						while (label_mol[i][h][1] != 10000)
						{
							k = 0;
							while (label_mol[j][k][0] != 10000)
							{
								leng = sqrt ((a[label_mol[i][h][1]][0][1]-a[label_mol[j][k][0]][0][0])*(a[label_mol[i][h][1]][0][1]-a[label_mol[j][k][0]][0][0]) + (a[label_mol[i][h][1]][1][1]-a[label_mol[j][k][0]][1][0])*(a[label_mol[i][h][1]][1][1]-a[label_mol[j][k][0]][1][0]) + (a[label_mol[i][h][1]][2][1]-a[label_mol[j][k][0]][2][0])*(a[label_mol[i][h][1]][2][1]-a[label_mol[j][k][0]][2][0]));
								if (leng < min)
									min = leng;
								k++;
							}
							h++;
						}

						if (min < bond_param[1])
						{
							k = 1;
							for (l=0; l<num_bond[label[i]]; l++)
								if (bond[label[i]][l] == label[j])
									k = 0;

							if (k == 1)
							{
								bond[label[i]][num_bond[label[i]]] = label[j];
								num_bond[label[i]]++;
								bond[label[j]][num_bond[label[j]]] = label[i];
								num_bond[label[j]]++;

								if (chs > 0)
								{
									bond_array[label[i]][label[j]] = (100*min00 - fmod(100*min00, 1));
									bond_array[label[j]][label[i]] = (100*min00 - fmod(100*min00, 1));
								}
							}
						}
					}
				}
			}
	break;
	}


	p = num_mol;
	
	for (i=0; i<num_mol; i++)
		bin[i] = 1;

	for (i=0; i<num_mol; i++)
		if (num_bond[i] == 0)
		{
			bin[i] = 0;
			agl[0]++;
			p--;
		}


	y = 0;
	while (p > 0)
	{
		x = 0;
		k = 0;
		while ((bin[x] == 0) && (x<num_mol))
		{
			x++;
			k = 1;
		}
		if ((bin[0] == 1) && (x == 0))
			k = 1;
		

		if (k == 1)
			for (i=0; i<y; i++)
				if (k == 1)
					for (j=0; j<label_num[i]; j++)
						if (k == 1)
							for (l=0; l<num_bond[x]; l++)
								if ((label[label_bond[i][j]] == label[bond[x][l]]) && (k == 1))
								{
									label_bond[i][label_num[i]] = x;
									label_num[i]++;
									bin[x] = 0;
									p--;
									k = 0;
								}


		if (k == 1)
		{
			label_num[y] = 1;
			label_bond[y][0] = x;
			bin[x] = 0;
			p--;

			for (i=0; i<label_num[y]; i++)
				for (j=0; j<num_bond[label_bond[y][i]]; j++)
					if (bin[bond[label_bond[y][i]][j]] == 1)
					{
						label_bond[y][label_num[y]] = bond[label_bond[y][i]][j];
						label_num[y]++;
						bin[bond[label_bond[y][i]][j]] = 0;
						p--;
					}

			y++;
		}
	}


	i = 0;
	while ((label_num[i] != 0) && (i < 650))
	{
		agl[label_num[i]-1]++;

		i++;
	}


	fprintf (fo, "STATISTICS:\n");
	for (i=0; i<350; i++)
		if (agl[i] != 0)
		{
			fprintf (fo, "%3i   -   ", i+1);
			fprintf (fo, "%4i\n", agl[i]);
		}
	fprintf (fo, "______________________________\n");


	for (i=0; i<350; i++)
		agl_all[i] += agl[i];


	i = 0;
	while ((label_num[i] != 0) && (i < 650))
	{
		fprintf (fo, "    %i", label_num[i]);

		if (chs == 2)
		{
			k = 0;
			for (j=0; j<label_num[i]; j++)
				k += num_bond[label_bond[i][j]] - 1;
			if (k == (label_num[i]-2))
			{
				fprintf (fo, "\tlinear\n");
				linear++;
			}
			else
			{
				l = k - label_num[i];
				l = l / 2;
				fprintf (fo, "\tcycle (%i)\n", l+1);
				cycle++;
			}

		}
		else
			fprintf (fo, "\n");

		for (j=0; j<label_num[i]; j++)
		{
			fprintf (fo, "%-5i   -", mol[label_bond[i][j]]);
			for (k=0; k<num_bond[label_bond[i][j]]; k++)
			{
				fprintf (fo, "   %-5i", mol[bond[label_bond[i][j]][k]]);

				if (chs > 0)
				{
					l = bond_array[label_bond[i][j]][bond[label_bond[i][j]][k]];
					all_bond_stat[l-1]++;
					q[0] = conv (l, 1);
					q[1] = conv (l, 2);
					q[2] = conv (l, 3);
					fprintf (fo, "( %c.%c%c)", q[2], q[1], q[0]);
				}
			}
			fprintf (fo, "\n");
		}

		
		i++;
	}

	fprintf (fo, "____________________________________________________________\n");
}



void all_stat(FILE *fo, int chs)
{
	int i;
	double k, l, t[2];
	char q[3];


	fprintf (fo, "\nSUMMARY STATISTIC:\n");


	for (i=0; i<250; i++)
		if (agl_all[i] != 0)
		{
			t[0] = agl_all[i];
			t[1] = step;
			k = t[0] / t[1];
			t[1] = t[1] * num_mol;
			l = t[0] / t[1] * (i+1);
			fprintf (fo, "%3i   -   %7i   %7.2f   %8.5f\n", i+1, agl_all[i], k, l);
		}


	if (chs > 0)
	{
		fprintf (fo, "____________________\n");

		k = 0;
		for (i=0; i<500; i++)
			k += all_bond_stat[i];

		for (i=0; i<500; i++)
			if (all_bond_stat[i] != 0)
			{
				q[2] = conv(i+1, 3);
				q[1] = conv(i+1, 2);
				q[0] = conv(i+1, 1);
				t[0] = i + 1;
				t[1] = t[0] / (bond_param[0] * 100);
				t[0] = all_bond_stat[i];
				t[0] = t[0] / k;
				fprintf (fo, "%c.%c%c (%7.4f)   -   %4i   %7.5f\n", q[2], q[1], q[0], t[1], all_bond_stat[i], t[0]);
			}


		if (chs == 2)
		{
			i = linear + cycle;
			t[0] = i;
			t[1] = linear;
			t[1] = t[1] / t[0];
			fprintf (fo, "____________________\n");
			fprintf (fo, "Linear molecules   -   %5i (%8.5f)\n", linear, t[1]);
			t[1] = cycle;
			t[1] = t[1] / t[0];
			fprintf (fo, "Cycle molecules    -   %5i (%8.5f)\n", cycle, t[1]);
		}
	}
}



void agl_stat (FILE *fo)
{
	int i, j, h, k, l, molecule;
	int num_bond[1000], bond[1000][20], bin[1000], label_bond[350], label_num;
	double leng, min, min00;
	char q[3];


	for (i=0; i<num_mol; i++)
		if (mol[i] == num_agl_atom)
			molecule = i;


	for (j=0; j<350; j++)
	{
		label_bond[j] = 0;
	}
	label_num = 0;

	for (i=0; i<1000; i++)
	{
		for (j=0; j<20; j++)
		{
			bond[i][j] = 0;
		}
		num_bond[i] = 0;
	}


	switch (type_int)
	{
	case 1:
		for (i=0; i<num_mol_ext; i++)
			for (j=i+1; j<num_mol_ext; j++)
			{
				min = sqrt ((a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][0]][0][0])*(a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][0]][0][0]) + (a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][0]][1][0])*(a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][0]][1][0]) + (a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][0]][2][0])*(a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][0]][2][0]));
				h = 0;
				while (label_mol[label[i]][h][0] != 10000)
				{
					k = 0;
					while (label_mol[label[j]][k][0] != 10000)
					{
						leng = sqrt ((a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][0]][0][0])*(a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][0]][0][0]) + (a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][0]][1][0])*(a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][0]][1][0]) + (a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][0]][2][0])*(a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][0]][2][0]));
						if (leng < min)
							min = leng;
						k++;
					}
					h++;
				}

				if (min < bond_param[0])
				{
					k = 1;
					for (l=0; l<num_bond[label[i]]; l++)
						if (bond[label[i]][l] == label[j])
							k = 0;
					if ((num_bond[label[i]] == 0) && (i>(num_mol-1)))
						k = 0;

					if (k == 1)
					{
						bond[label[i]][num_bond[label[i]]] = label[j];
						num_bond[label[i]]++;
						bond[label[j]][num_bond[label[j]]] = label[i];
						num_bond[label[j]]++;

						bond_array[label[i]][label[j]] = (100*min - fmod(100*min, 1));
						bond_array[label[j]][label[i]] = (100*min - fmod(100*min, 1));
					}
				}
			}
	break;
	
	case 2:
		for (i=0; i<num_mol_ext; i++)
			for (j=i+1; j<num_mol_ext; j++)
			{
				min = sqrt ((a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][0]][0][0])*(a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][0]][0][0]) + (a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][0]][1][0])*(a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][0]][1][0]) + (a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][0]][2][0])*(a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][0]][2][0]));
				h = 0;
				while (label_mol[label[i]][h][0] != 10000)
				{
					k = 0;
					while (label_mol[label[j]][k][0] != 10000)
					{
						leng = sqrt ((a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][0]][0][0])*(a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][0]][0][0]) + (a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][0]][1][0])*(a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][0]][1][0]) + (a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][0]][2][0])*(a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][0]][2][0]));
						if (leng < min)
							min = leng;
						k++;
					}
					h++;
				}

				if (min < bond_param[0])
				{
					min00 = min;
					min = sqrt ((a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][1]][0][1])*(a[label_mol[i][0][0]][0][0]-a[label_mol[j][0][1]][0][1]) + (a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][1]][1][1])*(a[label_mol[i][0][0]][1][0]-a[label_mol[j][0][1]][1][1]) + (a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][1]][2][1])*(a[label_mol[i][0][0]][2][0]-a[label_mol[j][0][1]][2][1]));
					h = 0;
					while (label_mol[label[i]][h][0] != 10000)
					{
						k = 0;
						while (label_mol[label[j]][k][1] != 10000)
						{
							leng = sqrt ((a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][1]][0][1])*(a[label_mol[i][h][0]][0][0]-a[label_mol[j][k][1]][0][1]) + (a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][1]][1][1])*(a[label_mol[i][h][0]][1][0]-a[label_mol[j][k][1]][1][1]) + (a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][1]][2][1])*(a[label_mol[i][h][0]][2][0]-a[label_mol[j][k][1]][2][1]));
							if (leng < min)
								min = leng;
							k++;
						}
						h++;
					}

					if (min < bond_param[1])
					{
						k = 1;
						for (l=0; l<num_bond[label[i]]; l++)
							if (bond[label[i]][l] == label[j])
								k = 0;
						if ((num_bond[label[i]] == 0) && (i>(num_mol-1)))
							k = 0;

						if (k == 1)
						{
							bond[label[i]][num_bond[label[i]]] = label[j];
							num_bond[label[i]]++;
							bond[label[j]][num_bond[label[j]]] = label[i];
							num_bond[label[j]]++;

							bond_array[label[i]][label[j]] = (100*min00 - fmod(100*min00, 1));
							bond_array[label[j]][label[i]] = (100*min00 - fmod(100*min00, 1));
						}
					}
					else
					{
						min = sqrt ((a[label_mol[i][0][1]][0][1]-a[label_mol[j][0][0]][0][0])*(a[label_mol[i][0][1]][0][1]-a[label_mol[j][0][0]][0][0]) + (a[label_mol[i][0][1]][1][1]-a[label_mol[j][0][0]][1][0])*(a[label_mol[i][0][1]][1][1]-a[label_mol[j][0][0]][1][0]) + (a[label_mol[i][0][1]][2][1]-a[label_mol[j][0][0]][2][0])*(a[label_mol[i][0][1]][2][1]-a[label_mol[j][0][0]][2][0]));
						h = 0;
						while (label_mol[label[i]][h][1] != 10000)
						{
							k = 0;
							while (label_mol[label[j]][k][0] != 10000)
							{
								leng = sqrt ((a[label_mol[i][h][1]][0][1]-a[label_mol[j][k][0]][0][0])*(a[label_mol[i][h][1]][0][1]-a[label_mol[j][k][0]][0][0]) + (a[label_mol[i][h][1]][1][1]-a[label_mol[j][k][0]][1][0])*(a[label_mol[i][h][1]][1][1]-a[label_mol[j][k][0]][1][0]) + (a[label_mol[i][h][1]][2][1]-a[label_mol[j][k][0]][2][0])*(a[label_mol[i][h][1]][2][1]-a[label_mol[j][k][0]][2][0]));
								if (leng < min)
									min = leng;
								k++;
							}
							h++;
						}

						if (min < bond_param[1])
						{
							k = 1;
							for (l=0; l<num_bond[label[i]]; l++)
								if (bond[label[i]][l] == label[j])
									k = 0;
							if ((num_bond[label[i]] == 0) && (i>(num_mol-1)))
								k = 0;

							if (k == 1)
							{
								bond[label[i]][num_bond[label[i]]] = label[j];
								num_bond[label[i]]++;
								bond[label[j]][num_bond[label[j]]] = label[i];
								num_bond[label[j]]++;

								bond_array[label[i]][label[j]] = (100*min00 - fmod(100*min00, 1));
								bond_array[label[j]][label[i]] = (100*min00 - fmod(100*min00, 1));
							}
						}
					}
				}
			}
	break;
	}


	for (i=0; i<num_mol; i++)
		bin[i] = 1;

	
	bin[molecule] = 0;
	label_num = 1;
	label_bond[0] = molecule;
	for (i=0; i<label_num; i++)
		for (j=0; j<num_bond[label_bond[i]]; j++)
			if (bin[bond[label_bond[i]][j]] == 1)
			{
				label_bond[label_num] = bond[label_bond[i]][j];
				label_num++;
				bin[bond[label_bond[i]][j]] = 0;
			}

	fprintf (fo, "\nFILE:     %s\n", name);
	fprintf (fo, "%6i", label_num);
	k = 0;
	for (i=0; i<label_num; i++)
		k += num_bond[label_bond[i]] - 1;
	if ((k == (label_num-2)) || (label_num == 1))
	{
		fprintf (fo, "\tlinear\n");
	}
	else
	{
		l = k - label_num;
		l = l / 2;
		fprintf (fo, "\tcycle (%i)\n", l+1);
	}
	for (i=0; i<label_num; i++)
	{
		fprintf (fo, "%-5i   ", mol[label_bond[i]]);
		if (label_num > 1)
			fprintf (fo, "-");
		for (j=0; j<num_bond[label_bond[i]]; j++)
		{
			fprintf (fo, "   %-5i", mol[bond[label_bond[i]][j]]);

			l = bond_array[label_bond[i]][bond[label_bond[i]][j]];
			q[0] = conv (l, 1);
			q[1] = conv (l, 2);
			q[2] = conv (l, 3);
			fprintf (fo, "( %c.%c%c)", q[2], q[1], q[0]);
		}
		fprintf (fo, "\n");
	}

	fprintf (fo, "____________________________________________________________\n");
}



void main()
{
	FILE *f;
	FILE *f_in;
	FILE *f_out;
	int i, k, from, to, choise;
	char name_out_file[128], q[256];


	f_in = fopen ("input_stat.dat", "r");
	for (i=0; i<5; i++)
		fscanf (f_in, "%c", &q);
	fscanf(f_in, "%s", &name);
	for (i=0; i<18; i++)
		fscanf (f_in, "%c", &q);
	fscanf(f_in, "%i", &from);
	fscanf(f_in, "%i", &to);
	fgets (q, 256, f_in);
	if (from > to) 
	{
		i = from; 
		from = to; 
		to = i;
	}
	for (i=0; i<15; i++)
		fscanf (f_in, "%c", &q);
	for (i=0; i<3;i++)
		fscanf(f_in, "%lf", &cell_param[i]);
	fgets (q, 256, f_in);
	for (i=0; i<9; i++)
		fscanf (f_in, "%c", &q);
	fscanf (f_in, "%i", &choise);
	fgets (q, 256, f_in);
	for (i=0; i<12; i++)
		fscanf (f_in, "%c", &q);
	fscanf (f_in, "%i", &type_int);
	fgets (q, 256, f_in);
	for (i=0; i<11; i++)
		fscanf (f_in, "%c", &q);
	for (i=0; i<type_int; i++)
		fscanf (f_in, "%i", &mol_atom_arr[i]);
	fgets (q, 256, f_in);
	for (i=0; i<9; i++)
		fscanf (f_in, "%c", &q);
	for (i=0; i<type_int; i++)
		fscanf(f_in, "%lf", &bond_param[i]);
	fgets (q, 256, f_in);
	for (i=0; i<20; i++)
		fscanf (f_in, "%c", &q);
	fscanf (f_in, "%i", &num_agl_atom);
	fgets (q, 256, f_in);
	for (i=0; i<7; i++)
		fscanf (f_in, "%c", &q);
	fscanf(f_in, "%s", &name_out_file);
	fclose (f_in);


	step = to - from + 1;
	k = strlen(name);


	f_out=fopen(name_out_file, "w+");
	fprintf (f_out, "stat_general ::: v.3.0 ::: 14/06/2010\n\n");
	fprintf (f_out, "%s\n%i - %i\n\n",name, from, to);
	fprintf (f_out, "Cell parametrs:\t%6.3f\t%6.3f\t%6.3f\n", cell_param[0], cell_param[1], cell_param[2]);
	fprintf (f_out, "Intermolecular bond parametrs:");
	for (i=0; i<type_int; i++)
		fprintf (f_out, "\t%5.2f", bond_param[i]);
	fprintf (f_out, "\n");
	if (choise == 3)
		fprintf (f_out, "Search molecule:%8i\n\n", num_agl_atom);
	else
		fprintf (f_out, "\n");

	for (i=from; i<to+1; i++)
	{
		name[k]='.';
		name[k+1]=conv(i,3);
		name[k+2]=conv(i,2);
		name[k+3]=conv(i,1);
		name[k+4]='\0';
		f=fopen(name, "r");

		if (f == NULL) 
			printf("File %s not found\n",name);
		else 
		{
			printf("File %s opened.",name);
			input_data(f);
			printf (".");
			if (choise == 3)
				agl_stat(f_out);
			else
				stat(f_out, choise);
			printf (".");
			fclose (f);
			printf ("...Ok!\n");
		}
	}

	if (choise != 3)
		all_stat(f_out, choise);
}
