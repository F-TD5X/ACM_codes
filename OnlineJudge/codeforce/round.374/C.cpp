#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5005;
int pre[maxn][maxn],to[maxn],nxt[maxn],top[maxn],v[maxn];
int Q[maxn],dp[maxn][maxn],deg[maxn];
int h,t,n,m,lim,cnt;

void Link(int x,int y,int w)
{
	to[++cnt]=y;
	nxt[cnt]=top[x];
	v[cnt]=w;
	top[x]=cnt;
}

void topsort()
{
	memset(dp,64,sizeof(dp));
	dp[1][1]=0;
	for(int i=1;i<=n;i++)
		if(deg[i]==0)
			Q[++t]=i;
	while(h<t)
	{
		int x=Q[++h];
		for(int i=top[x];i;i=nxt[i])
		{
			for(int j=1;j<=n;j++)
			{
				if(dp[x][j]+v[i]<dp[to[i]][j+1])
				{
					dp[to[i]][j+1]=dp[x][j]+v[i];
					pre[to[i]][j+1]=x;
				}
			}
			if(!--deg[to[i]])
				Q[++t]=to[i];
		}
	}
}

void print(int x,int y)
{
	if(!y)
		return ;
	print(pre[x][y],y-1);
	cout << x <<" ";
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n >> m >> lim;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin >> x >> y >> z;
		Link(x,y,z);
		deg[y]++;
	}
	topsort();
	for(int i=n;i>=1;i--)
	{
		if(dp[n][i]<=lim)
		{
			cout << i<<endl;
			print(n,i);
			break;
		}
	}
	return 0;
}
