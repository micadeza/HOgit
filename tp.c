#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio (int *m1,int n,int m,float p);

int main () {
	srand(time(NULL));
	int *m1;
	int i;
	int n=10; //filas
	int m=10;  //columnas	
	//float p=0.5;
	
	
	
	m1= (int*)malloc(n*m*sizeof(int));
	
	
	aleatorio (m1, 10, 10, 0.5);
	
	
	
	int j;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			printf("%d ",m1[i*m+j]);
			}
		printf("\n");
	}
	
	return 0;
}


void aleatorio (int *m1,int n,int m,float p) {
	float a;
	int i;
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

}
