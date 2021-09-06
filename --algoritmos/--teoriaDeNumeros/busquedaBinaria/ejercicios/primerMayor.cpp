#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int n;
int x;
int A[10000];

bool f(int numero){
    return numero > x; // Verificamos si el numero es mayor a x  
}

void bs(){
    int ini = 0; // Inicio comienza en 0
    int fin = n - 1; // Fin es la ultima casilla de arreglo

    while(ini < fin){ //Verifica si el inicio es menor que el final
        int mid = (ini + fin)/2; //Conseguimos el medio del arreglo
        if(f(A[mid])){//Utiliza la funcion para ver si el valor del medio es mayor a x
            fin = mid;
        }else{
            ini = mid + 1;
        }
    }
    if(f(A[ini])){
        cout<<A[ini]<<endl;
    }else{
        cout<<"No hay elementos mayores"<<endl;
    }
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    cin>>x;
    bs();
}