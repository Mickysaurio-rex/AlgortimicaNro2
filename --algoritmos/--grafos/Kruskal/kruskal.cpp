#include <bits/stdc++.h> 
// Variables
#define MAX_N 10000    // Maximo numero de vertices o nodos

using namespace std; 

// parent y rango sirven para el union find 
int parent[MAX_N];
int rango[MAX_N];

int n, m; // n numero de nodos y m numero de aristas 

void init() { // Iniciar el arbol
    for(int i=0;  i<= MAX_N; i++) {
        parent[i] = i; //Todos los nodos son sus propios padres
        rango[i] = 0; //Los nodos aún no están emparejados, por lo tanto no tienen rango
    }
}

int find(int x) { //Nos avisa quién es el padre mayor de cada nodo
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA,int nodeB) { // componente que nos avisa si está en el mismo arbol componente
    return find(nodeA) == find(nodeB); // Pregunta si el padre del nodo A es igual al padre del nodo B para ver si forman un ciclo
}

void unionRango(int x,int y) { // Une dos nodos para que esté balanceado 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ //Creamos una estructura
    int origen; //Nodo inicio
    int destino; //Nodo final
    double peso; //Cuanto pesa ir de uno a otro
    Arista(){}
    // sobrecarga del operador < para ordenar las aristas
    // sort 
    bool operator<(const Arista &a) const { //Ordenar a partir del peso
        if(peso == a.peso) {
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }
    }
}aristas[MAX_N]; //Cramos un arreglo de Aristas

Arista MST[MAX_N]; // n-1 aristas 

int numAristasArbol;
double kruskal(int nroNodos, int nroAristas) { 
    
    int origen, destino;
    double peso;

    double total = 0; // total del arbol de expansión minimo, guardamos todo el peso 

    numAristasArbol = 0; // contar el numero de aristas 

    init(); // Iniciar el union Find 
    
    sort(aristas,aristas + nroAristas); // ordena las aristas por su peso
     

    for (int i = 0; i < nroAristas; i++){ //Recorrer cada una de las aristas

        origen = aristas[i].origen; // Inicio en la posicion i
        destino = aristas[i].destino;// Final en la posicion i
        peso = aristas[i].peso;// Peso en la posicion i

        if(!sameComponent(origen,destino)) { // Verificamos si los dos nodos forman un ciclo 
            total += peso; //Sumamos el peso
            unionRango(origen,destino);  // Unimos los nodos
            MST[numAristasArbol] = aristas[i]; // Guardamos la arista agregada
            numAristasArbol++; // Incrementados la posicion para la futura arista
            
        }
    }
    return total; //Devolvemos el total del recorrido
}

int main(){
    while(scanf("%d %d",&n,&m) != EOF) {
        for(int i=0; i<m; i++) {
            scanf("%d %d %lf",&aristas[i].origen,&aristas[i].destino,&aristas[i].peso);
        }
        printf("%.2lf\n",kruskal(n,m));
        
        for(int i = 0 ;i <numAristasArbol;i++) { // Imprimo el arbol de expasion minimo
            cout<<MST[i].origen<<" "<<MST[i].destino<<" "<<MST[i].peso<<endl;
        }
    }

    return 0;
}