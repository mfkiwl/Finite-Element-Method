typedef struct 
{
	int span;
	double start;
	double end;
	double step;
	double *slice;
} Slice;

typedef struct
{
	int label;
	double value;
} Dirichlet;

typedef struct
{
	int column;
	int row;
	int layer;
	double x;
	double y;
	double z;
	double u;
	Dirichlet dirichlet;
} Map;

typedef struct
{
	int * node;
} Number;

typedef struct
{
	int rank;
	double ** forward; // 3 x 3
	double ** inverse; // 3 x 3
	double determinant;
} Jacobian;

typedef struct
{
	int row;
	int column;
	double * node;
	double ** differential; // 3 x 8
} ShapeFunction;

void transponse(int row, int column, double ** m, double ** n);

double determinant(int rank, double ** m);

void multiply(int p, int q, int r, double ** m, double ** n, double ** l);

void inverse(int rank, double ** m, double ** n);

void lu(int rank, double ** A, double ** lu);