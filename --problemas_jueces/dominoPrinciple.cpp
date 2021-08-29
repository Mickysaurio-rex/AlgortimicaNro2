#include<bits/stdc++.h>
using namespace std;
struct st{
  int x;
  int h;
  int dp;
  int  id;
}a[100000];

bool  comp(st node1,st node2) {
  return node1.x>node2.x;
}

int suma[1000000];

int main(){
   int n;
    cin>>n;
    for(int i=0;i<n;i++) {
         int x,h;
         scanf("%d %d",&x,&h);
         a[i].x=x;
         a[i].h=h;
         a[i].id=i;
  }
  
  sort(a,a+n,comp);
  for(int i=0;i<n;i++)a[i].dp=1;
  
  for(int i=1;i<n;i++){
    int j;
    for(j=i-1;j>=0;j-=a[j].dp){
      if(a[j].x>a[i].x+a[i].h-1)
        break;
        a[i].dp+=a[j].dp;
      }
   }
  
   for(int i=0;i<n;i++){
      suma[a[i].id]=a[i].dp;
    }
    for(int i=0;i<n;i++){
        cout<<suma[i]<<" ";
    } 
 }
