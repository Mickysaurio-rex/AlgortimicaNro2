#include <bits/stdc++.h>

using namespace std;

# define N 4

bool esValido(int tablero[N][N], int fila, int col) { 
    for(int i = 0; i<col; i++) {
        if(tablero[fila][i]) { 
            return false;
        }
    }
    for(int i = fila, j = col; i>=0 && j>=0; i--, j--) {
        if(tablero[i][j]) {
            return false;
        }
    }
    for(int i = fila, j = col; i<N && j>=0; i++, j--) {
        if(tablero[i][j]) {
            return false;
        }
    }
    return true;
}


bool solve_queen(int tablero[N][N],int col) { 

    if(col>=N) { 
        return true;
    }

    for(int i = 0; i<N; i++) { 
        if(esValido(tablero, i, col)) {
            tablero[i][col] = 1; 
            if(solve_queen(tablero, col+1)) { 
                return true; 
            }
            tablero[i][col] = 0; 
        }
    }
    return false;
}

void printSolution(int tablero[N][N]) {
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            cout<<tablero[i][j]<<endl;
        }
    }
}