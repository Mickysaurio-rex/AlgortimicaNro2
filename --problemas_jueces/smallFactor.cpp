#include <bits/stdc++.h> 
using namespace std;
long long n;
long long x;
vector<long long>numeritos;
bool f(int number) {
    return number > x;
}

void bs() {
    int ini = 0;
    int fin = n - 1;
    while(ini < fin ) {
        int mid = (ini + fin) / 2;
        if(f(numeritos[mid])) {  /// MOdificar la funcion de condicion
            fin = mid -1 ;
        } else {
            ini = mid;
        }
    }
    if(f(numeritos[fin])) {
        cout<<numeritos[fin]<<endl;
    }else {
        cout<<"No hay elementos mayores"<<endl;
    }
}

int main() {
    for(int dosP = 0; dosP <= 31; dosP++){
        for(int tresP = 0; tresP<=31; tresP++){
            numeritos.push_back(pow(2,dosP)*pow(3,tresP));
        }
    }
    while(cin>>x && x){
         
    n = numeritos.size();
    //lower_bound()
    sort(numeritos.begin(), numeritos.end());
    cout<<*lower_bound(numeritos.begin(),numeritos.end(),x)<<endl;
    }
}
