#include <iostream>  
#include <algorithm>  
#include <vector>  
using namespace std;  
#define MAX 1005  
#define INF 0x7fffffff  
  
int N,M,S,E,W;  
vector<vector<int> > val(MAX,vector<int>(MAX,INF));  
  
long long prim(){  
    long long res=0;  
    vector<bool> vis(MAX,false);  
    vector<int> min(MAX,INF);  
    min[1]=0;  
    for(int i=1;i<=N;i++){  
        int j,k;  
        for(k=-1,j=1;j<=N;j++)  
            if(!vis[j]&&(k==-1||min[j]<min[k]))  
                k=j;  
        vis[k]=1;  
        res+=min[k];  
        for(int i=1;i<=N;i++)  
            if(!vis[i]&&val[k][i]<min[i])  
                min[i]=val[k][i];  
    }  
    return res;  
}  
int main(){  
    cin>>N>>M;  
    for(int i=0;i<M;i++){  
        cin>>S>>E>>W;  
        val[S][E]=val[E][S]=W;  
    }  
    cout<<prim()<<endl;  
    return 0;  
}  
