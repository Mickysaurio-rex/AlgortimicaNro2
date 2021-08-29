#include <bits/stdc++.h>
using namespace std;
const int maxn=10001;
int padres[maxn],offset[maxn];
int encontrarlos(int x){
    if(x!=padres[x]){
        int tmp=padres[x];
        padres[x]=encontrarlos(padres[x]);
        offset[x]=(offset[x]+offset[tmp])%2;
    }
    return padres[x];
}

int Union(int x,int y,int d){
    int fx=encontrarlos(x);
    int fy=encontrarlos(y);
    if(fx==fy){
        if((offset[x]-offset[y]+2)%2!=d)
            return -1;
        else
            return 1;
    }
    padres[fy]=fx;
    offset[fy]=(offset[x]-offset[y]+d+2)%2;
    return 0;
}

void init(int n){
    for(int i=0;i<=n;i++)
        padres[i]=i;
    memset(offset,0,sizeof(offset));
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        int x,y,d;
        init(n);
        while(cin>>d>>x>>y,x+y+d){
            if(d<=2){
                d--;
                if(Union(x,y,d)==-1){
                    cout<<-1<<endl;
                }
            }
            else {
                d-=3;
                padres[y]=encontrarlos(y);
                padres[x]=encontrarlos(x);

                if(padres[x]==padres[y]&&(offset[x]-offset[y]+2)%2==d)
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
        }
    }
    return 0;
}
