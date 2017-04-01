#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio (int *m1,int n,int m,float p);
void print (int *m1, int n, int m);

int main () {
	srand(time(NULL));
	int *m1;
	int i;
	int n; //filas
	int m;  //columnas	
	float p;

	printf("Escriba la probabilidad:");
	scanf(" %f",&p);	
	printf("Escriba la cantidad de filas de la red:");
	scanf(" %i",&n);
	printf("Escriba la cantidad de columnas:");
	scanf(" %i",&m);

	m1= (int*)malloc(n*m*sizeof(int));
	
	
	aleatorio (m1, n, m, p);
	print (m1, n, m);
	
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

void print (int *m1,int n,int m) {

		int i;
		int j;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			printf("%d ",m1[i*m+j]);
			}
		printf("\n");
	}
}
	
