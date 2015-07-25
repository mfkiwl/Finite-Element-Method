#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start = 0, end = 0;
double duration;
double determinant(int rank, double ** m);
void inverse(int rank, double ** m, double ** n);
int main(int argc, char const *argv[])
{
	start = clock();
	int i = 0, j = 0, r = 3;
	double ** m = NULL, ** n = NULL;
	m = (double **) malloc(r * sizeof(double *));
	n = (double **) malloc(r * sizeof(double *));
	for(i = 0; i < r; i++)
	{
		m[i] = NULL;
		n[i] = NULL;
		m[i] = (double *) malloc(r * sizeof(double));
		n[i] = (double *) malloc(r * sizeof(double));
		for(j = 0; j < r; j++)
		{
			m[i][j] = 0.0;
			n[i][j] = 0.0;
		}
	}
	m[0][0] = 1.0;
	m[0][1] = 2.0;
	m[0][2] = 3.0;
	m[1][0] = 4.0;
	m[1][1] = 6.0;
	m[1][2] = 7.0;
	m[2][0] = 12.0;
	m[2][1] = 23.0;
	m[2][2] = 48.0;
	inverse(r, m, n);
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < r; j++)
		{
			printf("m[%d][%d] = %f\t", i, j, m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < r; j++)
		{
			printf("n[%d][%d] = %f\t", i, j, n[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < r; i++)
	{
		free(m[i]);
		m[i] = NULL;
		free(n[i]);
		n[i] = NULL;		
	}
	free(m);
	m = NULL;
	free(n);
	n = NULL;
	end = clock();
	duration = (double) (end - start) / CLOCKS_PER_SEC;
	printf("duration  = %f sec\n", duration);
	return 0;
}