#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mp[300][300];
int n;
bool vis[300][300];
int ans=0;

struct P
{
	ll x,y;
	P(ll x=0,ll y=0):x(x),y(y){}
}po[300];

ll dis2(P a,P b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int m;
void dfs(int rt,int dis=-1,int cnt=1)
{
	if(rt==m)
		ans=max(ans,cnt);
	for(int i=1;i<=n;i++)
	{
		if(dis==-1||dis==mp[rt][i])
		{
			if(!vis[rt][i])
			{
				vis[rt][i]=1;
				dfs(i,mp[rt][i],cnt+1);
			}
		}
	}
}



int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	int T;
	cin >> T;
	while(T--)
	{
		memset(mp,0,sizeof(mp));
		ans=0;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&po[i].x,&po[i].y);
		}
		if(n<=3)
		{
			puts("-1");
			continue;
		}
		bool flag=0;
		for(ll dis,i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					mp[i][j]=0x3f3f3f3f;
					continue;
				}
				dis=dis2(po[i],po[j]);
				mp[i][j]=dis;
				mp[j][i]=dis;
			}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			m=i;
			dfs(i,-1,0);
		}
		cout << ans<<endl;
	}
	return 0;
}
