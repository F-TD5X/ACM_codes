#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
int n,m;
ll T;
int g[5005][5005];
int vis[5005];
vector<int>ans,tmp,v[5005];

void bfs(int f,vector<int>& u,ll tot,int d)
{
	if(f==n)
	{
		if(u.size()>ans.size()&&tot<=T)
			ans=u;
		return;
	}
	else if(v[f].size()==0||tot>T||vis[f]&&vis[f]>=d)
		return;
	vis[f]=d;
	for(int i=0;i<v[f].size();i++)
	{
		u.push_back(v[f][i]);
		bfs(v[f][i],u,tot+1LL*g[f][v[f][i]],d+1);
		u.pop_back();
	}
}

int main()
{

	scanf("%d%d%d",&n,&m,&T);
	memset(vis,0,sizeof(vis));
	int a,b,t;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&t);
		v[a].push_back(b);
		g[a][b]=t;
	}
	tmp.push_back(1);
	bfs(1,tmp,0LL,1);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	cout<<endl;
    return 0;
}
