#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

string number;
int dp[20][2][20];
 
bool isPrime(int n) {   
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}
 
int solve_dp(int pos, int mayor,int sumaDigitos) {
    if(pos > number.size()) { 
        return 0;
    }
    if(pos == number.size()) {
        if(sumaDigitos % 5 == 0) { 
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[pos][mayor][sumaDigitos] == -1) {  
        int tope = 9;
        if(mayor == true) {  
            tope = number[pos]-'0';   
        }
        dp[pos][mayor][sumaDigitos] = 0;
        for(int digito = 0; digito <= tope; digito++) {
            if(digito == tope ) {
                dp[pos][mayor][sumaDigitos] += solve_dp(pos+1, true, digito+sumaDigitos);
            }
            else { 
                dp[pos][mayor][sumaDigitos] += solve_dp(pos+1, false, digito+sumaDigitos);
            }
        }
    }
    return dp[pos][mayor][sumaDigitos];
}

int main(){

    int  a = 1;
    int b = 15;
    // calculando f(a)
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(0, true, 0);
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    number = to_string(b);
    int pares_hasta_b = solve_dp(0, true, 0);
    // total para f(a,b) = f(b) - f(a-1)
    cout<< pares_hasta_b - pares_hasta_a;
    return 0;
}