void lu(int rank, double ** A, double ** LU)
{
	int i = 0, j = 0, k = 0;
	for (i = 1; i < rank; i++)
	{
		for(j = 0; j < rank; j++)
		{
			LU[i][j] = 0.0;		
		}
	}
	for(j = 0; j < rank; j++)
	{
		LU[0][j] = A[0][j];
	}
	for (i = 1; i < rank; i++)
	{
		for(j = 0; j < i; j++)
		{
			LU[i][j] = A[i][j];
			for(k = 0; k < j; k++)
			{
				LU[i][j] -= LU[i][k] * LU[k][j];
			}
			LU[i][j] /= LU[j][j];
		}
		for(j = i; j < rank; j++)
		{
			LU[i][j] = A[i][j];
			for(k = 0; k < i; k++)
			{
				LU[i][j] -= LU[i][k] * LU[k][j];
			}
		}
	}
}
