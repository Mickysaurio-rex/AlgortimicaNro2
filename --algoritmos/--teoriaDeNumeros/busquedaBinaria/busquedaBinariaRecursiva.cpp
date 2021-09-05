#include <iostream>

using namespace std;

int busquedaBinaria(int arreglo[], int busqueda, int izquierda, int derecha){
    if (izquierda > derecha){
      return -1;  
    } 
    int laMitad = (izquierda + derecha) / 2;
 
    int valorMedio = arreglo[laMitad];
    if (busqueda == valorMedio){
        return laMitad;
    }
    
    if (busqueda < valorMedio){
        derecha = laMitad - 1;
    }else{
        izquierda = laMitad + 1;
    }
    return busquedaBinaria(arreglo, busqueda, izquierda, derecha);
}


