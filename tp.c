#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	srand(time(NULL));
	int *m1;
	int i;
	int n=10; //filas
	int m=10;  //columnas	
	float p=0.5;
	float a;
	
	
	m1= (int*)malloc(n*m*sizeof(int));
	
	for (i=0;i<n*m;i++) {
			a=(rand()/(float)RAND_MAX);	
			//printf("%f\n",a);		
			if (p<a) {
				m1[i]=0;
			} 
			else {
				m1[i]=1;
			}
		}
	//printf("%d\n",m1[4]);
	
	
	
	int j;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			printf("%d ",m1[i*m+j]);
			}
		printf("\n");
	}
	
	return 0;
}
