#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>

#define MAX 1000000
 
using namespace std;
 
vector<unsigned long long> buildVector() {
    vector<unsigned long long> powers;
    unsigned long long power;
    for(unsigned long long i = 0; i < MAX; i++) {
        power = i*i;
        powers.push_back(power);
        
    }
    return powers;
}

unsigned long long binarySearch(vector<unsigned long long> a, unsigned long long l, unsigned long long r, unsigned long long x) {
    if (r >= l) {
        unsigned long long mid = (l+r) / 2;
  
        if (a[mid] == x){
            return a[mid];
        }
           
        //cout<<"mid: "<<a[mid]<<endl;
        if (a[mid] > x){
            return binarySearch(a, l, mid - 1, x);
        }
       
        return binarySearch(a, mid + 1, r, x);

    }
    return l;
}

 
int main() {
    unsigned long long m;
    while(scanf("%lld", &m)) {
        
        
        vector<unsigned long long> v = buildVector();
        //sort(v.begin(), v.end());
        if(m == 0){
            break;
        }
        unsigned long long low = binarySearch(v, 0, v.size()-1, m);
        if(binarySearch(v, 0, v.size()-1, m)){
            cout<<"true";
        }else{
            cout<<"false";
        }
       
        //cout<<(low == m)<<endl;
        
        
    }
    return 0;
 
}