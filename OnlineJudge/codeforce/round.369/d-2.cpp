#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod=1e9+7;
const int maxn=2*1e5+10;
int h[maxn],nx[maxn<<1],t[maxn<<1],etot=1;
vector<int> cnt[maxn];
ll pOw[maxn];
int n,m[maxn],tot;
ll ans=1;
bool v[maxn];

int dfs(int x,int p=-1)
{
    v[x]=1;
    for(int i=h[x];i;i=nx[i])
    {
        if(!m[t[i]])
        {
            m[t[i]]=m[x]+1;
            dfs(t[i],i/2);
        }
        else if(i/2!=p&&v[t[i]])
        {
            ans=ans*(pOw[m[x]-m[t[i]]+1]-2+mod)%mod;
            tot-=m[x]-m[t[i]]+1;
        }
    }
    v[x]=0;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d-2.in","r",stdin);
    //freopen("d-2.out","w",stdout);
#endif
    pOw[0]=1;
    for(int i=1;i<=maxn;i++)
        pOw[i]=pOw[i-1]*2%mod;
    cin >> n;
    tot=n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        nx[++etot]=h[i];
        h[i]=etot;
        t[etot]=x;
        nx[++etot]=h[x];
        h[x]=etot;
        t[etot]=i;
    }
    for(int i=1;i<=n;i++)
        if(!m[i])
        {
            m[i]=1;
            dfs(i);
        }
    cout << ans*pOw[tot]%mod<<endl;
    return 0;
}
