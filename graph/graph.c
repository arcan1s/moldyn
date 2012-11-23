#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <math.h>



int n, p[100];
double sol_a[100], sol_b[100][100], a[100][100], b[100][100];



void open()
{
	FILE *f;
	int i, j;
	char q[256];


	f = fopen ("graph.txt", "r");
	fscanf (f, "%i", &n);
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			fscanf (f, "%lf", &a[i][j]);
	fgets (q, 256, f);
	fgets (q, 256, f);
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			fscanf (f, "%lf", &b[i][j]);
	fclose (f);
}



void equat(double c[100][100], int rang, int z)
{
	int i, j, k, imax;
	double  max, res;


	for (i=0; i<n; i++)
		if (i == rang)
			c[i][n] = 1;
		else
			c[i][n] = 0;


	for(i=0; i<n; i++)
	{
		imax = 0;
		max = 0;

		for(j=i; j<n; j++)
		{
			if (fabs(c[j][i]) > max)
			{
				max = fabs(c[j][i]); 
				imax = j;
			}
		}

		for(j=0; j<=n; j++)
		{
			res = c[i][j];
			c[i][j] = c[imax][j];
			c[imax][j] = res;
		}

		for(j=0; j<n; j++)
		{
			if (j != i)
			{
				res = c[j][i] / c[i][i];
				for(k=i; k<=n; k++)
					c[j][k] = c[j][k] - (res * c[i][k]);
			}
		}
	}

	
	for (i=0; i<n; i++)
		switch (z)
		{
		case 0:
			sol_a[i] = c[i][n] / c[i][i];
			break;

		case 1:
			sol_b[i][rang] = c[i][n] / c[i][i];
			break;
		}
}



void iso()
{
	double work_a[100][100], work_b[100][100], bb[100][100];
	int i, j, k, l;
	double sum_a, sum_b;

	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
		{
			work_a[i][j] = a[i][j];
			work_b[i][j] = b[i][j];
		}


	for (j=0; j<n; j++)
	{	
		work_a[j][j]++;
		equat(work_a, j, 0);
		

		for (k=0; k<n; k++)
		{
			for (i=0; i<n; i++)
				for (l=0; l<n; l++)
					bb[i][l] = work_b[i][l];

			bb[k][k]++;
			equat(bb, k, 1);
		}


		for (k=0; k<n; k++)
		{
			sum_a = 0;
			sum_b = 0;
			for (i=0; i<n; i++)
			{
				sum_a += sol_a[i] * sol_a[i];
				sum_b += sol_b[i][k] * sol_b[i][k];
			}

			if ((sum_a == sum_b) && (sol_a[j] == sol_b[k][k]))
			{
				for (i=0; i<j; i++)
					if (p[i] == (k+1))
						l = 1;

				if (l != 1)
				{
					p[j] = k + 1;
					work_b[k][k]++;
				}
			}
		}
	}
}



void main()
{
	int i, j;


	open();
	for (i=0; i<n; i++)
		p[i] = 0;
	iso();


	for (i=0; i<n; i++)
		printf ("%i\t", p[i]);

	for (i=0; i<n; i++)
		if (p[i] == 0)
			j = 1;

	if (j != 1)
		printf ("\nGraphs are isomorthic.\n");
	else
		printf ("\nGraphs aren't isomorthic.\n");
	
	getch();
}
