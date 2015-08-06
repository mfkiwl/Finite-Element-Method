#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"
clock_t start = 0, stop = 0;
double duration = 0.0;
int main(int argc, char const *argv[])
{
	start = clock();
	int i = 0, j = 0, k = 0;
	double b = 0.0;
	double f = 1.0;
	Slice x, y, z;
	x.span = 10;
	x.start = 0.0;
	x.end = 6.0 / 1000;
	x.step = (x.end -  x.start) / x.span;
	x.slice = (double *) malloc((1 + x.span) * sizeof(double));
	for(i = 0; i < 1 + x.span; i++)
	{
		x.slice[i] = x.start + x.step * i;
	}
	y.span = 20;
	y.start = 0.0;
	y.end = 10.0 / 1000;
	y.step = (y.end - y.start) / y.span;
	y.slice = (double *) malloc((1 + y.span) * sizeof(double));
	for(i = 0; i < 1 + y.span; i++)
	{
		y.slice[i] = y.start + y.step * i;
	}
	z.span = 84;
	z.start = 0.0;
	z.end = 10.5 / 1000;
	z.step = (z.end -  z.start) / z.span;
	z.slice = (double *) malloc((1 + z.span) * sizeof(double));
	for(i = 0; i < 1 + z.span; i ++)
	{
		z.slice[i] = z.start + z.step * i;
	}
	Map * node = NULL;
	node = (Map *) malloc((1 + x.span) * (1 + y.span) * (1 + z.span) * sizeof(Map));
	for(i = 0; i < (1 + x.span) * (1 + y.span) * (1 + z.span); i++)
	{
		node[i].column = i;
		node[i].column %= (1 + x.span);
		node[i].x = x.start + x.step * node[i].column;
		node[i].row = i;
		node[i].row %= (1 + x.span) * (1 + y.span);
		node[i].row /= (1 + x.span);
		node[i].y = y.start + y.step * node[i].row;
		node[i].layer = i;
		node[i].layer /= (1 + x.span) * (1 + y.span);
		node[i].z = z.start + z.step * node[i].layer;
		node[i].u = 0.0;
		node[i].dirichlet.label = 0;
		node[i].dirichlet.value = 0.0;
	}
	for(i = 0; i < (1 + x.span); i++)
	{
		for(j = 0; j < (1 + y.span); j++)
		{
			node[i + (1 + x.span) * j].dirichlet.label = 1;
			node[i + (1 + x.span) * j].dirichlet.value = 0.0;
		}
	}

	for(i = 0; i < (1 + x.span); i++)
	{
		for(j = 0; j < (1 + y.span); j++)
		{
			node[i + (1 + x.span) * j + (1 + x.span) * (1 + y.span) * z.span].dirichlet.label = 1;
			node[i + (1 + x.span) * j + (1 + x.span) * (1 + y.span) * z.span].dirichlet.value = 0.0;
		}
	}

	for(i = 0; i < (1 + x.span); i++)
	{
		for(k = 0; k < (1 + z.span); k++)
		{
			node[i + (1 + x.span) * y.span + (1 + x.span) * (1 + y.span) * k].dirichlet.label = 1;
			node[i + (1 + x.span) * y.span + (1 + x.span) * (1 + y.span) * k].dirichlet.value = 0.0;
		}
	}

	for(i = 0; i < (1 + x.span) * (1 + y.span) * (1 + z.span); i++)
	{
		if(fabs(node[i].z - 5.25e-3) < 0.25e-3 + 0.5 * z.step)
		{
			if(node[i].y < 3e-3 + 0.5 * y.step)
			{
				node[i].dirichlet.label = 1;
				node[i].dirichlet.value = 1.0;
			}
		}
	}
	for(i = 0; i < (1 + x.span); i++)
	{
		for(j = 0; j < (1 + y.span); j++)
		{
			node[i + (1 + x.span) * j].dirichlet.label = 1;
			node[i + (1 + x.span) * j].dirichlet.value = 0.0;
		}
	}

	for(i = 0; i < (1 + x.span); i++)
	{
		for(j = 0; j < (1 + y.span); j++)
		{
			node[i + (1 + x.span) * j + (1 + x.span) * (1 + y.span) * z.span].dirichlet.label = 1;
			node[i + (1 + x.span) * j + (1 + x.span) * (1 + y.span) * z.span].dirichlet.value = 0.0;
		}
	}

	for(i = 0; i < (1 + x.span); i++)
	{
		for(k = 0; k < (1 + z.span); k++)
		{
			node[i + (1 + x.span) * y.span + (1 + x.span) * (1 + y.span) * k].dirichlet.label = 1;
			node[i + (1 + x.span) * y.span + (1 + x.span) * (1 + y.span) * k].dirichlet.value = 0.0;
		}
	}
	for(i = 0; i < (1 + x.span) * (1 + y.span) * (1 + z.span); i++)
	{
		if(fabs(node[i].z - 5.25e-3) < 0.25e-3 + 0.5 * z.step)
		{
			if(node[i].y < 3e-3 + 0.5 * y.step)
			{
				node[i].dirichlet.label = 1;
				node[i].dirichlet.value = 1.0;
			}
		}
	}
	int column = 0, row = 0, layer = 0;
	Number * element = NULL;
	element =  (Number *) malloc(x.span * y.span * z.span * sizeof(Number));
	for(i = 0; i < (x.span * y.span * z.span); i++)
	{
		layer = i;
		layer /= x.span * y.span;
		row = i;
		row %= x.span * y.span;
		row /= x.span;
		column = i;
		column %= x.span;
		element[i].node = NULL;
		element[i].node = (int *) malloc(8 * sizeof(int));
		element[i].node[0] = column + (1 + x.span) * row + (1 + x.span) * (1 + y.span) * layer;
		element[i].node[1] = element[i].node[0] + 1;
		element[i].node[2] = element[i].node[0] + 1 + x.span;
		element[i].node[3] = element[i].node[2] + 1;
		element[i].node[4] = element[i].node[0] + (1 + x.span) * (1 + y.span);
		element[i].node[5] = element[i].node[1] + (1 + x.span) * (1 + y.span);
		element[i].node[6] = element[i].node[2] + (1 + x.span) * (1 + y.span);
		element[i].node[7] = element[i].node[3] + (1 + x.span) * (1 + y.span);
	}
	Jacobian jacobian;
	jacobian.rank = 3;
	jacobian.forward = NULL;
	jacobian.inverse = NULL;
	jacobian.forward = (double **) malloc(jacobian.rank * sizeof(double *));
	jacobian.inverse = (double **) malloc(jacobian.rank * sizeof(double *));
	for(i = 0; i < jacobian.rank; i++)
	{
		jacobian.forward[i] = (double *) malloc(jacobian.rank * sizeof(double));
		jacobian.inverse[i] = (double *) malloc(jacobian.rank * sizeof(double));
		for(j = 0; j < jacobian.rank; j++)
		{
			jacobian.forward[i][j] = 0.0;
			jacobian.inverse[i][j] = 0.0;
		}
	}
	jacobian.determinant = 0.0;
	ShapeFunction shapeFunction;
	shapeFunction.row = 3;
	shapeFunction.column = 8;
	shapeFunction.node = NULL;
	shapeFunction.node = (double *) malloc(shapeFunction.column * sizeof(double));
	for(i = 0; i < shapeFunction.column; i++)
	{
		shapeFunction.node[i] = 0.0;
	}
	shapeFunction.differential = NULL;
	shapeFunction.differential = (double **) malloc(shapeFunction.row * sizeof(double *));
	for(i = 0; i < shapeFunction.row; i++)
	{
		shapeFunction.differential[i] = NULL;
		shapeFunction.differential[i] = (double *) malloc(shapeFunction.column * sizeof(double));
		for(j = 0; j < shapeFunction.column; j++)
		{
			shapeFunction.differential[i][j] = 0.0;
		}
	}

	double ** K = NULL;
	double * F = NULL;
	K = (double **) malloc((1 + x.span) * (1 + y.span) * (1 + z.span) * sizeof(double *));
	F = (double *) malloc((1 + x.span) * (1 + y.span) * (1 + z.span) * sizeof(double));
	for(i = 0; i < (1 + x.span) * (1 + y.span) * (1 + z.span); i++)
	{
		K[i] = NULL;
		K[i] = (double *) malloc((1 + x.span) * (1 + y.span) * (1 + z.span) * sizeof(double));
		F[i] = 0.0;
		for(j = 0; j < (1 + x.span) * (1 + y.span) * (1 + z.span); j++)
		{
			K[i][j] = 0.0;
		}
	}
	for(i = 0; i < (x.span * y.span * z.span); i++)
	{
		int p = 0, q = 0, r = 0, s = 0, t = 0;
		double xi = 0.0, eta = 0.0, zeta = 0.0;
		double tmp[3] = {0.0};
		for(j = 0; j < 8; j++)
		{
			xi = -pow((double)-1, (double)(j % 2)) / sqrt((double)3);
			eta =  -pow((double)-1, (double)((j / 2) % 2)) / sqrt((double)3);
			zeta = -pow((double)-1, (double)((j / 4) % 2)) / sqrt((double)3);
			shapeFunction.node[0] = (1 - xi) * (1 - eta) * (1 - zeta) / 8;
			shapeFunction.node[1] = (1 + xi) * (1 - eta) * (1 - zeta) / 8;
			shapeFunction.node[2] = (1 - xi) * (1 + eta) * (1 - zeta) / 8;
			shapeFunction.node[3] = (1 + xi) * (1 + eta) * (1 - zeta) / 8;
			shapeFunction.node[4] = (1 - xi) * (1 - eta) * (1 + zeta) / 8;
			shapeFunction.node[5] = (1 + xi) * (1 - eta) * (1 + zeta) / 8;
			shapeFunction.node[6] = (1 - xi) * (1 + eta) * (1 + zeta) / 8;
			shapeFunction.node[7] = (1 + xi) * (1 + eta) * (1 + zeta) / 8;
			shapeFunction.differential[0][0] = -(eta - 1) * (zeta - 1) / 8;
			shapeFunction.differential[0][1] =  (eta - 1) * (zeta - 1) / 8;
			shapeFunction.differential[0][2] =  (eta + 1) * (zeta - 1) / 8;
			shapeFunction.differential[0][3] = -(eta + 1) * (zeta - 1) / 8;
			shapeFunction.differential[0][4] =  (eta - 1) * (zeta + 1) / 8;
			shapeFunction.differential[0][5] = -(eta - 1) * (zeta + 1) / 8;
			shapeFunction.differential[0][6] = -(eta + 1) * (zeta + 1) / 8;
			shapeFunction.differential[0][7] =  (eta + 1) * (zeta + 1) / 8;
			shapeFunction.differential[1][0] = -(xi - 1) * (zeta - 1) / 8;
			shapeFunction.differential[1][1] =  (xi + 1) * (zeta - 1) / 8;
			shapeFunction.differential[1][2] =  (xi - 1) * (zeta - 1) / 8;
			shapeFunction.differential[1][3] = -(xi + 1) * (zeta - 1) / 8;
			shapeFunction.differential[1][4] =  (xi - 1) * (zeta + 1) / 8;
			shapeFunction.differential[1][5] = -(xi + 1) * (zeta + 1) / 8;
			shapeFunction.differential[1][6] = -(xi - 1) * (zeta + 1) / 8;
			shapeFunction.differential[1][7] =  (xi + 1) * (zeta + 1) / 8;
			shapeFunction.differential[2][0] = -(xi - 1) * (eta - 1) / 8;
			shapeFunction.differential[2][1] =  (xi + 1) * (eta - 1) / 8;
			shapeFunction.differential[2][2] =  (xi - 1) * (eta + 1) / 8;
			shapeFunction.differential[2][3] = -(xi + 1) * (eta + 1) / 8;
			shapeFunction.differential[2][4] =  (xi - 1) * (eta - 1) / 8;
			shapeFunction.differential[2][5] = -(xi + 1) * (eta - 1) / 8;
			shapeFunction.differential[2][6] = -(xi - 1) * (eta + 1) / 8;
			shapeFunction.differential[2][7] =  (xi + 1) * (eta + 1) / 8;
			for(p = 0; p < jacobian.rank; p++)
			{
				for(q = 0; q < jacobian.rank; q++)
				{
					jacobian.forward[p][q] = 0.0;
					jacobian.inverse[p][q] = 0.0;
				}
			}
			for(p = 0; p < 8; p++)
			{
				jacobian.forward[0][0] += shapeFunction.differential[0][p] * node[element[i].node[p]].x;
				jacobian.forward[0][1] += shapeFunction.differential[0][p] * node[element[i].node[p]].y;
				jacobian.forward[0][2] += shapeFunction.differential[0][p] * node[element[i].node[p]].z;
				jacobian.forward[1][0] += shapeFunction.differential[1][p] * node[element[i].node[p]].x;
				jacobian.forward[1][1] += shapeFunction.differential[1][p] * node[element[i].node[p]].y;
				jacobian.forward[1][2] += shapeFunction.differential[1][p] * node[element[i].node[p]].z;
				jacobian.forward[2][0] += shapeFunction.differential[2][p] * node[element[i].node[p]].x;
				jacobian.forward[2][1] += shapeFunction.differential[2][p] * node[element[i].node[p]].y;
				jacobian.forward[2][2] += shapeFunction.differential[2][p] * node[element[i].node[p]].z;
			}
			inverse((int) jacobian.rank, (double **) jacobian.forward, (double **) jacobian.inverse);
			jacobian.determinant = (double) determinant((int) 3, (double **) jacobian.forward);
			for(p = 0; p < 8; p++)
			{
				for(q = 0; q < 8; q++)
				{
					tmp[0] = shapeFunction.node[p] * shapeFunction.node[q];
					tmp[1] = 0.0;
					for(r = 0; r < 3; r++)
					{
						for(s = 0; s < 3; s++)
						{
							for(t = 0; t < 3; t++)
							{
								tmp[2] = shapeFunction.differential[r][p];
								tmp[2] *= jacobian.inverse[s][r];
								tmp[2] *= jacobian.inverse[s][t];
								tmp[2] *= shapeFunction.differential[t][q];
								tmp[1] += tmp[2];
							}
						}
					}
					K[element[i].node[p]][element[i].node[q]] += (tmp[1] - b * tmp[0]) * fabs(jacobian.determinant);
				}
				F[element[i].node[p]] += shapeFunction.node[p] * f * fabs(jacobian.determinant);
			}
		}
	}
	// for(i = 0; i < (1 + x.span) * (1 + y.span) * (1 + z.span); i++)
	// {
	// 	for(j = 0; j < (1 + x.span) * (1 + y.span) * (1 + z.span); j++)
	// 	{
	// 		printf("K[%d][%d] = %e\t", i, j, K[i][j]);
	// 	}
	// 	printf("F[%d] = %e\n", i, F[i]);
	// 	printf("\n");
	// }
	double ** LU = NULL;
	LU = (double **) malloc((1 + x.span) * (1 + y.span) * (1 + z.span) * sizeof(double *));
	for(i = 0; i < (1 + x.span) * (1 + y.span) * (1 + z.span); i++)
	{
		LU[i] = NULL;
		LU[i] = (double *) malloc((1 + x.span) * (1 + y.span) * (1 + z.span) * sizeof(double));
		for(j = 0; j < (1 + x.span) * (1 + y.span) * (1 + z.span); j++)
		{
			LU[i][j] = 0.0;
		}
	}
	lu((int) (1 + x.span) * (1 + y.span) * (1 + z.span), (double **) K, (double **) LU);
	free(x.slice);
	x.slice = NULL;
	free(y.slice);
	y.slice = NULL;
	free(z.slice);
	z.slice = NULL;
	free(node);
	node = NULL;
	for(i = 0; i < (x.span * y.span * z.span); i++)
	{
		free(element[i].node);
		element[i].node = NULL;
	}
	free(element);
	element = NULL;
	for(i = 0; i < jacobian.rank; i++)
	{
		free(jacobian.forward[i]);
		free(jacobian.inverse[i]);
		jacobian.forward[i] = NULL;
		jacobian.inverse[i] = NULL;
	}
	free(jacobian.forward);
	free(jacobian.inverse);
	jacobian.forward = NULL;
	jacobian.inverse = NULL;
	free(shapeFunction.node);
	shapeFunction.node = NULL;
	for(i = 0; i < shapeFunction.row; i++)
	{
		free(shapeFunction.differential[i]);
		shapeFunction.differential[i];
	}
	free(shapeFunction.differential);
	shapeFunction.differential = NULL;
	for (i = 0; i < (1 + x.span) * (1 + y.span) * (1 + z.span); i++)
	{
		free(K[i]);
		K[i] = NULL;
		free(LU[i]);
		LU[i] = NULL;
	}
	free(K);
	K = NULL;
	free(LU);
	LU = NULL;
	free(F);
	F = NULL;
	stop = clock();
	duration = ((double) (stop - start)) / (CLOCKS_PER_SEC);
	printf("duration = %e sec\n", duration);
	getchar();
	return 0;
}
