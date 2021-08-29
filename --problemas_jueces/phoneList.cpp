#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int t,n;
    string s;
    vector<string> listaP;
    bool estaBien;
    
    cin>>t;
    
    for(int caso=0;caso<t;caso++){
        cin>>n;
        
        listaP.clear();
        
        for(int i=0;i<n;i++){
            cin>>s;
            listaP.push_back(s);
        }
        
        sort(listaP.begin(),listaP.end());
        
        estaBien=true;
        
        for(int i=0;i<n-1;i++){
            if(listaP[i+1].size()>=listaP[i].size()){
                s=listaP[i+1].substr(0,listaP[i].size());
                if(s==listaP[i]){
                    estaBien=false;
                    break;
                }
            }
        }
        
        if(estaBien) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}
