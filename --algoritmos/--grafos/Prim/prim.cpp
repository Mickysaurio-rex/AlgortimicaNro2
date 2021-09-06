#include <stdio.h>
#define n 100 //maximo de vertices 
#define maxim 9999 
struct arista {
	//estructura con la que definimos las aristas resultantes del arbol generador de coste minimo
	int ver1;
	int ver2;
}
;
struct arista Ta[n];
void prim (int L[n][n]){ //Pedimos matriz de adyacencia	
	//Devuelve la tabla Ta[n].
	int proxim[n];
	int distmin[n];
	int min;
	int i, j;
	int c, k;
	int x;
	c=0;
	for(i=0; i<n; i++) {
		Ta[i].ver1=0;
		Ta[i].ver2=0;
	}
	for(i=0; i<n; i++) {
		proxim[i]=1;
		distmin[i]=L[i][0];
	}
	
    printf("n");
	for (i=1; i<n; i++) {
		min=maxim;
		for (j=1; j<n; j++) {
			if(0<=distmin[j]<min) {
				min=distmin[j];
				k=j;
			}
			Ta[c].ver1=proxim[k];
			Ta[c].ver2=k;
			c++;
			distmin[k]=-1;
		}
		for (j=1; j<n; j++) {
			x=L[j][k];
			if(x<distmin[j]) {
				distmin[k]=L[j][k];
				proxim[j]=k;
			}
		}
	}
}