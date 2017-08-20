#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3010;
const int inf=0x3f3f3f3f;
int v[maxn],vis[maxn],dis[maxn];
int n,m;
int g[maxn][maxn];

void solve()  
{  
    int i,j;  
    int ans = inf;  
    int maxx,maxi;  
    int s,t;  
    for(i = 1;i <= n;i ++)  
        v[i] = i; 
    while(n > 1)  
    {  
        memset(dis,0,sizeof(dis));  
        memset(vis,false,sizeof(vis));  
        for(i = 2;i <= n;i ++)  
        {  
            dis[v[i]] = g[v[1]][v[i]];  
        }  
        vis[v[1]] = true;  
        for(i = 1;i < n;i ++)  
        {  
            maxx = -1;  
            maxi = 0;  
            for(j = 1;j <= n;j ++)  
            {  
                if(vis[v[j]] == false && maxx < dis[v[j]])  
                {  
                    maxx = dis[v[j]];
                    maxi = j;  
                }  
            }  
            vis[v[maxi]] = true;  
            if(i == n - 2)  
                s = maxi;  
            if(i == n - 1)  
                t = maxi;  
            for(j = 1;j <= n;j ++)  
            {  
                if(vis[v[j]] == false)  
                    dis[v[j]] += g[v[maxi]][v[j]];  
            }  
        }  
        ans = min(ans,dis[v[t]]);  
        for(i = 1;i <= n;i ++)  
        {  
            g[v[s]][v[i]] += g[v[t]][v[i]];  
            g[v[i]][v[s]] = g[v[s]][v[i]];  
        }  
        v[maxi] = v[n];  
        n --;  
    }  
    printf("%d\n",ans);  
}  

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.1.in","r",stdin);
    //freopen("B.1.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m)){
		memset(g,0,sizeof(g));
		memset(v,0,sizeof(v));
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		for(int u,v,w,i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&w);
			g[u][v]=w;
			g[v][u]=w;
		}
		solve();
	}
	return 0;
}
