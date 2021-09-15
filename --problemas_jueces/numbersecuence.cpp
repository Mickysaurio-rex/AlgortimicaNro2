#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std; 
long long N,b; 
int main(){      
    cin>>N;     
    while(N--){          
        cin>>b;         
        int group_max_count=1,group_long=1;      
        while(b>group_long){
            group_max_count++;
            b-=group_long;
            int group_max_count2=group_max_count;
            while(group_max_count2>0)
            {
                group_max_count2/=10;
                group_long++;
            }
        }
        int j=1,m=9;
        while(b>m){
            b=b-m;
            j++;
            m=j*9*pow(10.0,j-1);
        } 
        int c=b/j,d; 
        if(b%j!=0){
            c++;
            d=j-b%j;
        }
        else{
            d=0;
        }
        int e=c+pow(10.0,j-1)-1;
        for(;d>0;d--){
            e/=10;
        }
        cout<<e%10<<endl;
    }      
    return 0; 
}