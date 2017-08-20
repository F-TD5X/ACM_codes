#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn=1e5;
vector<int> adj[maxn];
int dp[maxn][12];
bool vis[maxn];
int n,m,k;
int size,head[maxn];

struct G
{
	int v,nxt,w;
}E[maxn<<1];

void dfs(int u)
{
	vis[u]=1;
	for(int e=head[u];e!=-1;e=E[e].nxt)
	{
		int v=E[e].v;
		int w=E[e].w;
		if(vis[v])
			continue;
		dfs(v);
		for(int i=k;i>=1;i--)
		{
			for(int j=1;j<=i;j++)
				dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]+2*w-j*w);
		}
	}
}

void addEdge(int u,int v,int w)
{
	E[size].v=v;
	E[size].w=w;
	E[size].nxt=head[u];
	head[u]=size++;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("r-a.in","r",stdin);
    //freopen("r-a.out","w",stdout);
#endif
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		int sum=0;
		memset(head,-1,sizeof(head));
		size=0;
		for(int i=0,u,v,w;i<n-1;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			sum+=w;
			addEdge(u,v,w);
			addEdge(v,u,w);
		}
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		dfs(m);
		cout << sum*2-dp[m][k]<<endl;
	}
	return 0;
}
