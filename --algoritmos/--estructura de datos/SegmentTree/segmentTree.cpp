#include <bits/stdc++.h> 

using namespace std; 
int numeros[] = {1,2,3,4,5,6,7,8};

struct node{
    int maximo;
    int minimo;// crear una variable de acuerdo a la operacion(suma,resta,mminimo,maximo,etc)
}segmentTree[10000];// al poner seguido al corche, decimos que este arreglo es de tipo nodo

void init(int posicionInicial, int posicionFinal, int nodoActual){ //inicia los array y crea los nodos
    if(posicionInicial == posicionFinal){// caso base
        segmentTree[nodoActual].minimo = numeros[posicionInicial];
        segmentTree[nodoActual].maximo = numeros[posicionInicial];
    }else{
        int medio = (posicionInicial + posicionFinal)/2;
        int hijoIzq = 2 * nodoActual + 1; // colocamos al hijo izquierdo 
        int hijoDer = 2 * nodoActual + 2; // colocamos al hijo derecho
        init(posicionInicial, medio, hijoIzq); // funcion recursiva para ir por la izquierda
        init(medio + 1, posicionFinal, hijoDer); // funcion recursiva para ir la derecha
        segmentTree[nodoActual].minimo = min(segmentTree[hijoIzq].minimo, segmentTree[hijoDer].minimo);//actualizar el nodo actual
        segmentTree[nodoActual].maximo = max(segmentTree[hijoIzq].maximo, segmentTree[hijoDer].maximo);
    }
}

node query(int ini, int fin, int nodoActual, int i, int j){
    if(ini>= i && fin <= j){ //verifica si el rango esta dentro del array
        return segmentTree[nodoActual];
    }else{
        int medio = (ini + fin)/2;
        int hijoIzq = 2 * nodoActual + 1; // colocamos al hijo izquierdo 
        int hijoDer = 2 * nodoActual + 2; // colocamos al hijo derecho
        if(j < medio){
            return query(ini, medio, hijoIzq, i, j);// elimina la derecha
        }else if(i>medio){
            return query(medio + 1, fin, hijoDer, i, j);// elimina la izquierda
        }else {
            //usar los dos lados 
            node queryIzq = query(ini, medio, hijoDer, i, j);
            node queryDer = query(medio + 1, fin, hijoDer, i, j);
            node resultado;
            resultado.maximo = max(queryIzq.maximo, queryDer.maximo);
            resultado.minimo = min(queryIzq.maximo, queryDer.maximo);
            return resultado;
        }
    }

}

void update(int inicio, int final, int nodoActual, int posicion, int valor){
    if(posicion < inicio && valor > final){ //verifica si el rango esta dentro del array
        return ;
    }
    if(inicio == final){// caso base
        segmentTree[nodoActual].minimo = valor;
        segmentTree[nodoActual].maximo = valor;
    }else{
        int medio = (inicio + final)/2;
        int hijoIzq = 2 * nodoActual + 1; // colocamos al hijo izquierdo 
        int hijoDer = 2 * nodoActual + 2; // colocamos al hijo derecho
        init(inicio, medio, hijoIzq); // funcion recursiva para ir por la izquierda
        init(medio + 1, final, hijoDer); // funcion recursiva para ir la derecha
        segmentTree[nodoActual].minimo = min(segmentTree[hijoIzq].minimo, segmentTree[hijoDer].minimo);//actualizar el nodo actual
        segmentTree[nodoActual].maximo = max(segmentTree[hijoIzq].maximo, segmentTree[hijoDer].maximo);
    }
}

int main(){
    init(0,7,0); // parte de la posicion 0 (inicial) y termina en la posicion 7 (final)
    query(0,7,0,6,7);
    return 0;
}