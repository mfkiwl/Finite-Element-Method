void transponse(int row, int column, double ** m, double ** n)
{
	int i = 0, j = 0;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			n[j][i] = (double) m[i][j];
		}
	}
}