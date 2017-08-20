#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=100+5;
int f[maxn];
ll ans;
struct Node
{
    int x,y;
    ll v;
}G[maxn*maxn];
int n;

int fi(int x)
{
    return f[x]<0?x:fi(f[x]);
}

int cmp(Node a,Node b)
{
    return a.v<b.v;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
#endif
    int a,b,v;
    int fx,fy;
    while(~scanf("%d",&n) && n)
    {
        memset(f,-1,sizeof(f));
        ans=0;
        for(int i=0;i<n*(n-1)/2;i++)
            scanf("%d%d%d",&G[i].x,&G[i].y,&G[i].v);
        sort(G,G+n,cmp);
        for(int i=0;i<n*(n-1)/2;i++)
        {
            fx=fi(G[i].x);
            fy=fi(G[i].y);
            if(fx!=fy)
            {
                f[fx]=fy;
                ans+=G[i].v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
