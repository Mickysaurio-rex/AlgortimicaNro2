#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>


#define N 100000


static int padres[N];
static int rango[N];
static int elementos[N];


int maxi;

void makeSet(int n){
    for(int i = 0; i < n; ++i){
        padres[i]  = i;
        rango[i] = 0;
        elementos[i] = 1;
    }
}

int findSet(int x){
    if( x != padres[x] )
        padres[x] = findSet( padres[x] );
    return padres[x];
}

bool SameSet(int x, int y){
    return findSet(x) == findSet(y);
}


void link(int x, int y){

    if( !SameSet(x, y) ){

        if( rango[x] > rango[y] ){
            padres[y] = x;
            elementos[x] += elementos[y];
            maxi = ( maxi < elementos[x] ) ? elementos[x] : maxi;
        }
        else{
            padres[x] = y;
            elementos[y] += elementos[x];
            maxi = ( maxi < elementos[y] ) ? elementos[y] : maxi;

            if(rango[x] == rango[y])
                rango[y] = rango[y] + 1;
        }

    }
}

void Union(int x, int y){
    link( findSet(x), findSet(y) );
}



int main(){
    int n, m;
    int i, j;
    int times;
    scanf("%d", &times);
    while( times-- ){
        scanf("%d%d", &n, &m);

            makeSet(n);

            maxi = 1;
            while(m--){
                scanf("%d%d", &i, &j);
                --i, --j;
                Union(i, j);
            }
            printf("%d\n", maxi);
        }
    return 0;
}
