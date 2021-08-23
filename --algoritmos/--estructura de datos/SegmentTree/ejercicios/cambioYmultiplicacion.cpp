#include <bits/stdc++.h> 

using namespace std; 
int numeros[] = {1,2,3,4,5,6,7,8};

struct node{
    int maximo;
    int minimo;
    int producto;
}segmentTree[10000];

void init(int posicionInicial, int posicionFinal, int nodoActual){ 
    if(posicionInicial == posicionFinal){
        segmentTree[nodoActual].producto = numeros[posicionInicial];
    }else{
        int medio = (posicionInicial + posicionFinal)/2;
        int hijoIzq = 2 * nodoActual + 1;  
        int hijoDer = 2 * nodoActual + 2; 
        init(posicionInicial, medio, hijoIzq); 
        init(medio + 1, posicionFinal, hijoDer); 
         segmentTree[nodoActual].producto = segmentTree[hijoIzq].producto * segmentTree[hijoDer].producto;
    }
}

node query(int ini, int fin, int nodoActual, int i, int j){
    if(ini>= i && fin <= j){ 
        return segmentTree[nodoActual];
    }else{
        int medio = (ini + fin)/2;
        int hijoIzq = 2 * nodoActual + 1;  
        int hijoDer = 2 * nodoActual + 2; 
        if(j < medio){
            return query(ini, medio, hijoIzq, i, j);
        }else if(i>medio){
            return query(medio + 1, fin, hijoDer, i, j);
        }else {
            //usar los dos lados 
            node queryIzq = query(ini, medio, hijoDer, i, j);
            node queryDer = query(medio + 1, fin, hijoDer, i, j);
            node resultado;
            resultado.producto = queryIzq.producto * queryDer.producto;
            return resultado;
        }
    }

}

void update(int inicio, int final, int nodoActual, int posicion, int valor){
    if(posicion < inicio || valor > final){ 
        return ;
    }
    if(inicio == final){
        segmentTree[nodoActual].producto = valor;
    }else{
        int medio = (inicio + final)/2;
        int hijoIzq = 2 * nodoActual + 1;  
        int hijoDer = 2 * nodoActual + 2; 
        init(inicio, medio, hijoIzq); 
        init(medio + 1, final, hijoDer); 
        segmentTree[nodoActual].producto = segmentTree[hijoIzq].producto * segmentTree[hijoDer].producto;
    }
}

int main(){
    int queries;
    int n;
    while(cin>>n>>queries){
        for(int i = 0; i < n; i++){
            cin>>numeros[i];
            if(numeros[i]){
                numeros[i] = 1;
            }else if(numeros[i]<0){
                numeros[i]=-1;
            }
        }
        init(0,n-1,0);
        for(int i=0;i<queries;i++){
            char querie;
            cin>>querie;
            if('C' == querie){
                int posicion, valor;
                cin>>posicion>>valor;
                if(valor>0){
                    valor = 1;
                }else if(valor<0){
                    valor = -1;
                }
                update(0,n-1,0,posicion-1,valor);
            }else{
                int izquierda,derecha;
                cin>>izquierda>>derecha;
                int result = query(0,n-1,0,izquierda-1,derecha-1).producto;
                if(result == 0){
                    cout<<'0';
                }else if(result>0){
                    cout<<'+';
                }else{
                    cout<<'-';
                }
            }
        } 
     cout<<endl;
    } 
    return 0;
}