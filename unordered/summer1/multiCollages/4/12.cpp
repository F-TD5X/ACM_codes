#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int cas = 0;
int a[maxn],b[maxn];
int ans[maxn];
int l[maxn],r[maxn];
int d[maxn];
int lowbit(int x){
    return x&(-x);
}
void update(int x){
    for(int i=x;i<maxn;i+=lowbit(i)){
        d[i]++;
    }
}
int get(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans+=d[i];
    return ans;
}
void solve(){
    memset(d,0,sizeof(d));
    vector<pair<int,int> >V;
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        V.push_back(make_pair(a[i],i));
    }
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++){
        ans[i+1]=max(V[i].second,V[i].second+get(maxn-1)-get(V[i].second))-min(V[i].first,V[i].second);
        update(V[i].second);
    }
    printf("Case #%d:",++cas);
    for(int i=1;i<=n;i++){
        printf(" %d",ans[i]);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
