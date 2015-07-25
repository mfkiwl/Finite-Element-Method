#include <stdlib.h>
double determinant(int rank, double ** m)
{
   double det = 0.0;
   int i = 0, j = 0, r = 0, sgn = 1;
   if(rank == 1)
   {
      det += m[0][0];
   }
   else if(rank == 2)
   {
      det += m[0][0] * m[1][1] - m[0][1] * m[1][0];
   }
   else if(rank == 3)
   {
      det += m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
      det -= m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]);
      det += m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
   }
   else
   {
      double ** n = NULL;
      n = (double **) malloc((rank - 1) * sizeof(double *));
      for (i = 0; i < rank - 1; i++)
      {
         n[i] = NULL;
         n[i] = (double *) malloc((rank - 1) * sizeof(double));
         for(j = 0; j < rank - 1; j++)
         {
            n[i][j] = 0.0;
         }
      }
      for(r = 0; r < rank; r++)
      {
         for(i = 0; i < rank - 1; i++)
         {
            for(j = 0; j < rank - 1; j++)
            {
               if(i < r)
               {
                  n[i][j] = (double) m[i][j + 1];
               }
               else
               {
                  n[i][j] = (double) m[i + 1][j + 1];
               }
            }
         }
         det += sgn * m[r][0] * determinant(rank - 1, n);
         sgn *= -1;
      }
      for(i = 0; i < rank - 1; i++)
      {
         free(n[i]);
         n[i] = NULL;
      }
      free(n);
      n = NULL;
   }
   return det;
}
// double determinant(int rank, double ** m)
// {
//    double det = 0.0;
//    if(rank == 1)
//    {
//       det = (double) m[0][0];
//    }
//    else
//    {
//       int i = 0, j = 0, r = 0, sgn = 1;
//       double ** n = NULL;
//       n = (double **) malloc((rank - 1) * sizeof(double *));
//       for (i = 0; i < rank - 1; i++)
//       {
//          n[i] = NULL;
//          n[i] = (double *) malloc((rank - 1) * sizeof(double));
//          for(j = 0; j < rank - 1; j++)
//          {
//             n[i][j] = 0.0;
//          }
//       }
//       for(r = 0; r < rank; r++)
//       {
//          for(i = 0; i < rank - 1; i++)
//          {
//             for(j = 0; j < rank - 1; j++)
//             {
//                if(i < r)
//                {
//                   n[i][j] = (double) m[i][j + 1];
//                }
//                else
//                {
//                   n[i][j] = (double) m[i + 1][j + 1];
//                }
//             }
//          }
//          det += sgn * m[r][0] * determinant(rank - 1, n);
//          sgn *= -1;
//       }
//       for(i = 0; i < rank - 1; i++)
//       {
//          free(n[i]);
//          n[i] = NULL;
//       }
//       free(n);
//       n = NULL;
//       }
//       return det;
// }