#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

void  imprimir(int *red,int n)
{
  int i,j,k;
  for(i=0;i<n;i=i+1)
  {
    for(j=0;j<n;j=j+1)
    {
      if(red[i*n+j]==0) { printf("\x1B[0m %2.2d ",red[i*n + j]); }
      else
      {

        printf("\x1B[36m %2.2d ",red[i*n + j]);
      }
    }
    printf("\x1B[0m\n");
  }
  printf("\x1B[0m\n------\n");

}
