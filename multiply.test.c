// #include <stdio.h>
// #include <stdlib.h>
// void multiply(int p, int q, int r, double ** m, double ** n, double ** l);
// int main(int argc, char const *argv[])
// {
// 	double ** m = NULL, ** n = NULL, ** l = NULL;
// 	int p = 50, q = 110, r = 10;
// 	m = (double **) malloc(p * sizeof(double *));
// 	n = (double **) malloc(q * sizeof(double *));
// 	l = (double **) malloc(p * sizeof(double *));
// 	int i = 0, j = 0, k = 0;
// 	for(i = 0; i < p; i++)
// 	{
// 		m[i] = NULL;
// 		m[i] = (double *) malloc(q * sizeof(double));
// 		for(j = 0; j < q; j++)
// 		{
// 			m[i][j] = (double) j + q * i;
// 			printf("m[%d][%d] = %f\t", i, j, m[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// 	for(i = 0; i < q; i++)
// 	{
// 		n[i] = NULL;
// 		n[i] = (double *) malloc(r * sizeof(double));
// 		for(j = 0; j < r; j++)
// 		{
// 			n[i][j] = (double) j + r * i;
// 			printf("n[%d][%d] = %f\t", i, j, n[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// 	for(i = 0; i < p; i++)
// 	{
// 		l[i] = NULL;
// 		l[i] = (double *) malloc(r * sizeof(double));
// 		for(j = 0; j < r; j++)
// 		{
// 			l[i][j] = 0.0;
// 			printf("l[%d][%d] = %f\t", i, j, l[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// 	multiply(p, q, r, m, n, l);
// 	for(i = 0; i < p; i++)
// 	{
// 		for(j = 0; j < r; j++)
// 		{
// 			printf("l[%d][%d] = %f\t", i, j, l[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");

// 	for(i = 0; i < p; i++)
// 	{
// 		free(m[i]);
// 		m[i] = NULL;
// 	}
// 	free(m);
// 	m = NULL;

// 	for(i = 0; i < q; i++)
// 	{
// 		free(n[i]);
// 		n[i] = NULL;
// 	}
// 	free(n);
// 	n = NULL;

// 	for(i = 0; i < p; i++)
// 	{
// 		free(l[i]);
// 		l[i] = NULL;
// 	}
// 	free(l);
// 	l = NULL;
// 	return 0;
// }
#include <stdio.h>
int main(int argc, char const *argv[])
{
	double m[2][3] = {1.2, 1.3, 1.4, 2.5, 1.6, 1.7};
	double n[2][2] = {1.2, 1.3, 1.4, 2.5};
	double p[3][3] = {0.0};
	int i = 0, j = 0, r = 0, s = 0, t = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(r = 0; r < 2; r++)
			{
				for(s = 0; s < 2; s++)
				{
					for(t = 0; t < 2; t++)
					{
						p[i][j] += m[r][i] * n[s][r] * n[s][t] * m[t][j];
					}
				}
			}
			printf("p[%d][%d] = %f\t", i, j, p[i][j]);
		}
		printf("\n");
	}
	return 0;
}