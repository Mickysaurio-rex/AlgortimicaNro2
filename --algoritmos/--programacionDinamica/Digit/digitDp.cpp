#include <bits/stdc++.h>

using namespace std;

string numero = "307";
int dp[20][2][20];

int solveDp(int posicion, int mayor, int pares){ // creamos la funcion con los tres parametros requerido
    if(posicion > numero.size()){ //execde al tope y retorna 
        return 0;
    }

    if(posicion == numero.size()){ //llega a tope  
        if(pares == 2){//preguntamos si tiene dos pares el numero
            return 1;
        }else{
            return 0;
        }
    }

    if(dp[posicion][mayor][pares] == -1){// preguntamos si no se ha calculado
        int tope = 9;
        if(mayor == true){ // el numero puede llegar a pasarse del tope? 
            tope = numero[posicion] - '0'; // condicionamis que solo se puede usar los numeros menores altope
        }
        dp[posicion][mayor][pares] = 0;
        for(int digito = 0; digito <= tope; digito++){
            if(digito == tope){//si estuviera en el tope
                dp[posicion][mayor][pares] += solveDp(posicion+1,true,pares + digito%2 == 0);
            }else{//si aun no llegara al tope
                dp[posicion][mayor][pares] += solveDp(posicion+1,false,pares + digito%2 == 0);
            }
        }
    }
    return dp[posicion][mayor][pares];
}

int main(){
    int a = 20;
    int b = 30;
    numero = to_string(a);
    memset(dp,-1,sizeof(dp));
    int paresHastaA = solveDp(0,false,0);
    memset(dp,-1,sizeof(dp));
    int paresHastaB = solveDp(0,false,0);
    cout << paresHastaB - paresHastaA;
    return 0;   
}