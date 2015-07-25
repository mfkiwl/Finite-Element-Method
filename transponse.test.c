#include <stdio.h>
#include <stdlib.h>

void transponse(int row, int column, double ** m, double ** n);
int main(int argc, char *argv[])
{
	double ** m = NULL, ** n = NULL;
	int i = 0, j = 0;
	int row = 5, column = 10;
	m = (double **) malloc(row * sizeof(double *));
	n = (double **) malloc(column * sizeof(double *));
	for(i = 0; i < row; i++)
	{
		m[i] = NULL;
		m[i] = (double *) malloc(column * sizeof(double));
		for(j = 0; j < column; j++)
		{
			m[i][j] = (double) j + column * i;
			printf("m[%d][%d] = %f\t", i, j, m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < column; i++)
	{
		n[i] = NULL;
		n[i] = (double *) malloc(row * sizeof(double));
		for(j = 0; j < row; j++)
		{
			n[i][j] = 0.0;
			printf("n[%d][%d] = %f\t", i, j, n[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	transponse(row, column, m, n);
	for(i = 0; i < column; i++)
	{
		for(j = 0; j < row; j++)
		{
			printf("n[%d][%d] = %f\t", i, j, n[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < row; i++)
	{
		free(m[i]);
		m[i] = NULL;
	}
	free(m);
	m = NULL;
	for(i = 0; i < column; i++)
	{
		free(n[i]);
		n[i] = NULL;
	}
	free(n);
	n = NULL;
	return 0;
}