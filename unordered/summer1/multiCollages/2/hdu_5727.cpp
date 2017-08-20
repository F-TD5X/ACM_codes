#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N=10;
int n,m,u,v,ans,pos[N],link[N];
bool s[N][N],vis[N];
vector<int>eg[N];
bool dfs(int u)
{
    for(int i=0;i<eg[u].size();i++)
    {
        int v=eg[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            if(link[v]==-1||dfs(link[v]))
            {
                link[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    memset(s,0,sizeof(s));
    while(m--)
    {
        scanf("%d%d",&u,&v);
        s[u][v]=1;
    }
    ans=0x3f3f3f3f;
    for(int i=1; i<=n; i++)
        pos[i]=i;
    do
    {
        memset(link,-1,sizeof(link));
        for(int i=1; i<=n; i++)
        {
            eg[i].clear();
            for(int j=1; j<=n; j++)
            {
                u=pos[i];
                if(i==1) v=pos[n];
                else v=pos[i-1];
                if(s[j][u]||s[j][v]) continue;
                eg[i].push_back(j);
            }
        }
        int now=0;
        for(int i=1; i<=n; i++)
        {
            memset(vis,0,sizeof(vis));
            now+=dfs(i);
        }
        ans=min(ans,n-now);
    }
    while(next_permutation(pos+2,pos+n+1)&&ans);
    printf("%d\n",ans);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(!n)
        {
            puts("0");
            continue;
        }
        solve();
    }
    return 0;
}
