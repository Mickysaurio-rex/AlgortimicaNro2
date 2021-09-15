#include <bits/stdc++.h> 
using namespace std;
string nombre;
map<string ,int> animales; 
int padres[1000];
int rango[1000];//guardamos los niveles del padre
int cont[1000];

void init(){
    for(int i = 0; i < 1000; i++){//todos los elementos son sus propios padres
        padres[i] = i; //[0,1,2,3,4,5.....]
        rango[i] = 0; // colocamos la profundidad(rango) de los padres en 0 ya que no hay ninguna union aun
    }
}

void unir(int vertice1, int vertice2){// unir nodos
    padres[vertice2] = vertice1; //colocamos al vertice 1 como padre del vertice 2 
}

int encontrarAlPadre(int vertice){
    if(padres[vertice] == vertice){//caso base, comprueba si el vertice es su mismo padre
        return vertice; // retorna el vertice padre
    }
    return encontrarAlPadre(padres[vertice]); //funcion recursiva, llama al metodo para aplicarlo al padre del vertice inicial
}

int findComprimido(int vertice){
    if(padres[vertice] == vertice){
        return vertice;
    }else{
        padres[vertice] = findComprimido(padres[vertice]);//al tiempo de ser funcion recursiva, logra acortar el tiempo de consulta cambiando el padre del nodo
        return padres[vertice]; // retorna el padre del vertice
    }
}

void unionRango(int x, int y){
    int xRaiz = findComprimido(x); // Saca el padre del lado izquierdo
    int yRaiz = findComprimido(y); // Saca el padre del lado derecho
    if(rango[xRaiz] > rango[yRaiz]) {  //preguntamos si el lado zquierdo es mayor al derecho
        padres[yRaiz] = xRaiz; // padre de la derecha se vuelve hijo de la izquierda
        cont[yRaiz] += cont[xRaiz]; 
    } else {
        padres[xRaiz] = yRaiz; // padre de la izquierda se vuelve hijo de la derecha
        cont[xRaiz] += cont[yRaiz];
        if(rango[xRaiz] == rango[yRaiz]) { //preguntamos si son iguales
            rango[yRaiz]++;//aumenta el rango de la derecha
        }
    }
}
int main(){
    int n, x;
    cin>>n>>x;
    for(int i = 0; i<n; i++){
        string nombre;
        cin>>nombre;
        animales[nombre] = i;
    }

    cout<<animales.find("comer");
    return 0;
}