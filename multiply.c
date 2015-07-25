void multiply(int p, int q, int r, double ** m, double ** n, double ** l)
{
	int i = 0, j = 0, k = 0;
	for(i = 0; i < p; i++)
	{
		for(j = 0; j < r; j++)
		{
			l[i][j] = 0.0;
			for(k = 0; k < q; k++)
			{
				l[i][j] += m[i][k] * n[k][j];
			}
		}
	}
}