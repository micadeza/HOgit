#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio (int *red,int n,int m,float p);
void print (int *red, int n, int m);
int hoshen (int *red,int n,int m);
int actualizar (int *red,int s, int frag, int *clase);
void etiqueta_falsa(int *red,int *clase,int s1,int s2,int n);
void  corregir_etiqueta(int *red,int *clase,int n);
int   percola(int *red,int n);
void escribir(int z, float *probabilidad, int *percola);

int main () {
	srand(time(NULL));
	int *red;
	int i;
	int j;
	int n; //filas
	int m; //columnas	
	int P=16;
	int z=2;
	float prob;
	int denominador;
	int frag;
	int s;
	int *clase;
	int perc;

	//p=0.5;
	n=3;	
	m=3;
	red= (int*)malloc(n*m*sizeof(int));
	clase= (int*)malloc((n*m)*sizeof(int));	
	probabilidad= (float*)malloc(16*sizeof(float));
	percolacion=(int*)malloc(16*sizeof(int));
	pcritca=(float*)malloc
	
for(i=0;i<z;i++)
    {
      prob=0.5;
      denominador=2.0;
 
      srand(time(NULL));


      for(j=0;j<P;j++)
        {
          aleatorio(red,n,m,prob);
      
          hoshen(red,n,m);
        
          denominador=2.0*denominador;

          *(probabilidad + j) = prob;
	  *(percolacion) = percola(red,n);
          if (percola(red,n)) { 
             prob=prob-(1.0/denominador);
		} 
          else {	
		prob=prob+(1.0/denominador);
		}
	//printf ("\n");
	//printf("%d\n",perc);
	escribir(z,probabilidad,percolacion);
        }
    }
	
	return 0;
}


void aleatorio (int *red,int n,int m,float p) {
	float a;
	int i;
	for (i=0;i<n*m;i++) {
			a=(rand()/(float)RAND_MAX);	
			//printf("%f\n",a);		
			if (p<a) {
				red[i]=0;
			} 
			else {
				red[i]=1;
			}
	}

}

void print (int *red,int n,int m) {

		int i;
		int j;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			printf(" %d",red[i*m+j]);
			}
		printf("\n");
	}
}
	
int hoshen(int *red,int n,int m)
{
  /*
    Esta funcion implementa en algoritmo de Hoshen-Kopelman.
    Recibe el puntero que apunta a la red y asigna etiquetas 
    a cada fragmento de red. 
  */

  int i,j,k,s1,s2,frag;
  int *clase;

  frag=0; //frag es el numero de la etiqueta?
  
  clase=(int *)malloc(n*n*sizeof(int));

  for(k=0;k<n*m;k++) *(clase+k)=frag; //El for es solo esa linea. Y (clase+k)=frag es clase[k]=frag
  
  // primer elemento de la red

  s1=0; //""el de arriba"" no hhay conflicto.
  frag=2;
  if (*red) frag=actualizar(red,s1,frag,clase); //por si el primer elemtno es 0. 
  
  // primera fila de la red

  for(i=1;i<n;i++) 
    {
      if (*(red+i)) 
         {
           s1=*(red+i-1);  
           frag=actualizar(red+i,s1,frag,clase);
         }
	
    }
	
  // el resto de las filas 

  for(i=n;i<n*n;i=i+n)
    {

      // primer elemento de cada fila

      if (*(red+i)) 
         {
           s1=*(red+i-n); 
           frag=actualizar(red+i,s1,frag,clase);
         }

      for(j=1;j<n;j++)
	if (*(red+i+j))
	  {
	    s1=*(red+i+j-1); 
            s2=*(red+i+j-n);

	    if (s1*s2>0)
	      {
		etiqueta_falsa(red+i+j,clase,s1,s2,n);
	      }
	    else 
	      { if (s1!=0) frag=actualizar(red+i+j,s1,frag,clase);
	        else       frag=actualizar(red+i+j,s2,frag,clase);
	      }
	  }
    } 


  corregir_etiqueta(red,clase,n);
	/*for (i=0;i<n*n;i++) {
		printf ("%d\n",clase[i]);
		}*/	

  free(clase);


  return 0;
}

int actualizar (int *red,int s, int frag, int *clase) {
		
	if (s==0 && *(red))   {
	    *red = frag;
	    *(clase + frag) = frag;
	    frag++;
	  }
	else
  	{
    		*red = s;
	  }
return frag;
	
}

void etiqueta_falsa (int *red, int *clase, int s1, int s2, int n) {
	int i,j;	
		if (s1>s2) {
			*(red)=s2;
			*(clase + s1)=-s2;
			*(red - 1) = s2;
			}
		if (s1<s2) {
			*(red)=s1;
			*(clase + s2)=-s1;
			*(red-n) = s2;
		//*(clase + s1)=s2;
		}			
		if (s1==s2) {
			*(red)=actualizar(red,s1,s1,clase);
		}
}


/*void  corregir_etiqueta(int *red,int *clase,int n){
	int i,s;	
	for (i=1;i<n*n;i++) {
		s=*(red);
		while (*(clase+s)<=0) {
			s=-(*(clase+s));
			*(red)=s;
		
		}
		

	}

}*/

void  corregir_etiqueta(int *red,int *clase,int n)
{
  int i,s,p;
  for(i=0;i<n*n;i++)
  {
    s = *(red + i);

      p = *(clase + s);
      //if(p<0){
        while(p<0) { p = *(clase - p); }
        *(red + i) = p;
      //}

  }
}

/*int percola(int *red,int n) {
	int i,j,perc;
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			//printf("%d\n",red[(n-1)*n+j]);
			if (red[i]-red[(n-1)*n+j]==0) { 
				perc=1;
				break; }
			else {
				perc=0;
			}
			
			
			//printf("%d\n",red[n+2*j]);
			 }
			//printf("\n");
			//printf("%d\n",red[i]);
			}	
	printf("\n");
	printf("%d\n",perc);
		//printf("\n");
		//printf("%d\n",red[(n*n)-(n-1)+i]);	
		//}		
		
	
		
return perc;
}*/

int percola(int *red,int n) {
	int i,k,s,j,l,p,perc;
	int *v;
	v = (int*)malloc(n*sizeof(int));
	perc=0;
	for(k=0;k<n;k++) *(v+k)=0;

	for (i=0;i<n;i++) {
		if (red[i]!=0) {
			s=red[i];
			v[s]=s;
					
		}
	//printf("%d\n",v[i]);
	}

	//printf("\n");

	for (l=0;l<n;l++) {
		for (p=0;p<n;p++){
			
			//printf("%d\n",red[(n-1)*n+p]);
			//printf("%d\n", red[(n-1)*n+p]-v[l+2]);
			//printf("\n");
			if (red[(n-1)*n+p]-v[l+2]==0 && red[(n-1)*n+p]!=0) {
				
				perc=1;
				break;
			}
			/*if (perc==1) {
				break; }*/
		}
	}
	

		
	printf("%d\n",perc);
return perc;
}
