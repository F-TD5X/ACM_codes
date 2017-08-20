#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;

int arr[maxn * 4];

void update(int o,int l,int r,int ul,int ur,int v){
    if(ul <= l && r <= ur){
        arr[o] = v;
        return;
    }
    int m = (l + r) >> 1;
    if(arr[o] != -1){
        arr[o<<1] = arr[o<<1|1] = arr[o];
        arr[o] = -1;
    }
    if(ul <= m) update(o<<1,l,m,ul,ur,v);
    if(m+1<=ur) update(o<<1|1,m+1,r,ul,ur,v);
}

int query(int o,int l,int r,int pos){
    if(l == r){
        return arr[o];
    }
    if(arr[o] != -1) return arr[o];
    int m = (l + r) >> 1;;
    if(pos <= m) return query(o<<1,l,m,pos);
    else return query(o<<1|1,m+1,r,pos);
}

vector<int> in[maxn],out[maxn];
int L[maxn],R[maxn];
int v[maxn];

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        for(int i=0;i<=m+1;i++){
            in[i].clear();
            out[i].clear();
        }
        for(int i=1;i<n;i++) scanf("%d",&v[i]);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&L[i],&R[i]);
            if(L[i] > R[i])
                swap(L[i],R[i]);
        }

        memset(arr,-1,sizeof(arr));
        for(int i=m;i>=1;i--){
            update(1,1,n,L[i],R[i]-1,i);
        }
        for(int i=1;i<n;i++){
            int tim = query(1,1,n,i);
            if(tim != -1){
                in[tim].push_back(i);
            }
        }

        memset(arr,-1,sizeof(arr));
        for(int i=1;i<=m;i++){
            update(1,1,n,L[i],R[i]-1,i);
        }
        for(int i=1;i<n;i++){
            int tim = query(1,1,n,i);
            if(tim != -1){
                out[tim].push_back(i);
            }
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            for(auto x : in[i])
                ans += v[x];
            printf("%d\n",ans);
            for(auto x : out[i])
                ans -= v[x];
        }
    }
    return 0;
}
