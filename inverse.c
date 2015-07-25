#include <math.h>
#include <stdlib.h>
double determinant(int rank, double ** m);
void inverse(int rank, double ** m, double ** n)
{
	int i = 0, j = 0, p = 0, q = 0;
	double ** adj = NULL, det = 0.0;
	det = determinant(rank, m);
	for(i = 0; i < rank; i++)
	{
		for(j = 0; j < rank; j++)
		{
			n[i][j] = 0.0;
		}
	}
	adj = (double **) malloc((rank - 1) * sizeof(double *));
	for(i = 0; i < rank - 1; i++)
	{
		adj[i] = NULL;
		adj[i] = (double *) malloc((rank - 1) * sizeof(double));
		for(j = 0; j < rank - 1; j++)
		{
			adj[i][j] = 0.0;
		}
	}
	for(i = 0; i < rank; i++)
	{
		for(j = 0; j < rank; j++)
		{	
			for(p = 0; p < rank - 1; p++)
			{
				for(q = 0; q < rank - 1; q++)
				{
					if(p < i && q < j) adj[p][q] = m[p][q];
					else if(p >= i && q < j) adj[p][q] = m[p + 1][q];
					else if(p < i && q >= j) adj[p][q] = m[p][q + 1];
					else adj[p][q] = m[p + 1][q + 1];
				}
			}
			n[j][i] = pow((double)-1, (double)(i + j)) * determinant(rank - 1, adj) / det;
		}
	}
	for(i = 0; i < rank - 1; i++)
	{
		free(adj[i]);
		adj[i] = NULL;
	}
	free(adj);
	adj = NULL;
}