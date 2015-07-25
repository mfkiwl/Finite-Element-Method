#include <stdio.h>
#include <stdlib.h>
void lu(int rank, double ** A, double ** lu);
int main(int argc, char const *argv[])
{
	int i = 0, j = 0, r = 3;
	double ** A = NULL, ** LU = NULL;
	A = (double **) malloc(r * sizeof(double *));
	LU = (double **) malloc(r * sizeof(double *));
	for(i = 0; i < r; i++)
	{
		A[i] = (double *) malloc(r * sizeof(double));
		LU[i] = (double *) malloc(r * sizeof(double));
		for(j = 0; j < r; j++)
		{
			A[i][j] = 0.0;
			LU[i][j] = 0.0;
		}
	}
	A[0][0] = 1.2;
	A[0][1] = 1.3;
	A[0][2] = 1.4;
	A[1][0] = 2.2;
	A[1][1] = 2.4;
	A[1][2] = 3.4;
	A[2][0] = 1.9;
	A[2][1] = 2.9;
	A[2][2] = 1.1;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < r; j++)
		{
			// printf("A[%d][%d] = %f\t", i, j, A[i][j]);
			printf("%f\t", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	lu((int) r, (double **) A, (double **) LU);
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < r; j++)
		{
			// printf("LU[%d][%d] = %f\t", i, j, LU[i][j]);
			printf("%f\t", LU[i][j]);
		}
		printf("\n");
	}	
	for(i = 0; i < r; i++)
	{
		free(A[i]);
		free(LU[i]);
		A[i] = NULL;
		LU[i] = NULL;
	}
	free(A);
	A = NULL;
	free(LU);
	LU = NULL;
	return 0;
}