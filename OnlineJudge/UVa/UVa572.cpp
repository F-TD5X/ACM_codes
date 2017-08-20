#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char mp[111][111];
int vis[111][111];
int idx[111][111];
int cnt;
int n,m;

void dfs(int x,int y,int id)
{
	if(x<0 || x>=n || y<0 || y>=m)
		return;
	if(mp[x][y]!='@'|| vis[x][y])
		return;
	idx[x][y]=id;
	for(int dr=-1;dr<=1;dr++)
		for(int dc=-1;dc<=1;dc++)
			if(dr!=0 || dc!=0)
				dfs(x+dr,y+dc,id);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa572.in","r",stdin);
    //freopen("UVa572.out","w",stdout);
#endif
	while(cin>>n>>m && n+m)
	{
		cnt=0;
		memset(vis,0,sizeof(vis));
		memset(idx,0,sizeof(idx));
		for(int i=0;i<n;i++)
			cin >>mp[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(!vis[i][j] && idx[i][j]==0)
					dfs(i,j,++cnt);
		cout << cnt<<endl;
	}
	return 0;
}
