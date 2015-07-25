#include <stdio.h>
#include <stdlib.h>
double determinant(int rank, double ** m);
int main(int argc, char const *argv[])
{
	double ** m = NULL, det = 0.0;
	int r = 3;
	m = (double **) malloc(r * sizeof(double *));
	int i = 0, j = 0, k = 0;
	for(i = 0; i < r; i++)
	{
		m[i] = NULL;
		m[i] = (double *) malloc(r * sizeof(double));
		for(j = 0; j < r; j++)
		{
			m[i][j] = (double) (1 + j) * (1 + i + j);
			printf("m[%d][%d] = %f\t", i, j, m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	det = determinant(r, m);
	printf("determinant = %f\n", det);
	for(i = 0; i < r; i++)
	{
		free(m[i]);
		m[i] = NULL;
	}
	free(m);
	m = NULL;
	return 0;
}
