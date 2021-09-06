#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 101 

int grafo[MAX_N][MAX_N];   // capacidad + flujo  
int path[MAX_N];           // Guarda el recorrido     

// Edmonds Karp 
// DINIC 
int maxFlow(int s,int t) { 
    // s nodo inicial 
    // t nodo final 
    int maxFlow = 0; //Maximo flujo
    while(true) { /// Nunca sabemos si no tenemos flujo
        memset(path, -1, sizeof(path)); // No los estamos visitando, -1 es false
        queue<int> Q;
        Q.push(s);
        path[s] = s;  // Pone el primer nodo como su propio padre
        while(!Q.empty() && path[t]==-1) { // Mientras que la cola no este vacia y el final no haya sido visitado
            int currentNode = Q.front();
            Q.pop();
            for(int i = 0 ; i < MAX_N ; i++) {
                if(grafo[currentNode][i] > 0 && path[i]==-1)  {  // Verificamos si se puede visitar 
                    path[i] = currentNode;                       // Guarda el camino 
                    Q.push(i);                                  // Agregar a la cola
                }   
            }
        }
       
        if(path[t]==-1) { // Si llega a t el path tiene que ser diferente a -1, si no es diferente significa que no hubo camino
            break;
        }
        int minFlow = 1e9; // Infinito, valor determinado
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {//Va recorriendo el camino formado 
            minFlow = min(minFlow,grafo[from][to]); // grafo[from][to] capacidades de las aristas 
        }
        

        // V - 1 //  
        // Sumar al grafo residual y restar al grafo de capacidad ese minimo
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {//Va recorriendo el camino formado para colocar aristas de retorno
            grafo[from][to] -= minFlow; // grafo de capacidad
            grafo[to][from] += minFlow; // grafo residual
        }
 
        maxFlow += minFlow; //Va sumando para el maximo flujo
        
    }
    return maxFlow;//Retorna el maximo flujo
}



int main() {
input;
int nodes, aristas, nroCases = 1; 
while(cin>>nodes && nodes) {
    int s,t;   // s = fuente, t = terminal 
    cin>>s>>t>>aristas;
    memset(grafo,0,sizeof(grafo));
     for(int i=0;i<aristas;i++) {
        int from, to, capacity; 
        cin>>from>>to>>capacity;
        grafo[from][to] = capacity;          // camino capacidad
        grafo[to][from] = 0;                //  flujo camino residual 
    }
    cout<<maxFlow(s,t)<<endl;
    }    
}