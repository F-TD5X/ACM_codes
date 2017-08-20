/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=120;
char mp[maxn][maxn];
int n,m,vis[maxn][maxn],vis1[maxn][maxn];
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};


void dfs(int x,int y,int cnt){
	vis[x][y]=cnt;
	mp[x][y]='a'+cnt;
	for(int i=0;i<4;i++){
		if(mp[x+d[i][0]][y+d[i][1]]=='0' && !vis[x+d[i][0]][y+d[i][1]])
			dfs(x+d[i][0],y+d[i][1],cnt);
	}
}

void dfs1(int x,int y,int cnt){
	vis1[x][y]=cnt;
	mp[x][y]='A'+cnt;
	for(int i=0;i<4;i++)
		if(mp[x+d[i][0]][y+d[i][1]]=='1' && !vis1[x+d[i][0]][y+d[i][1]] )
			dfs1(x+d[i][0],y+d[i][1],cnt);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1006.in","r",stdin);
    //freopen("1006.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m)){
		int cnt=0,cnt1=0;
		memset(vis,0,sizeof(vis));
		memset(vis1,0,sizeof(vis1));
		memset(mp,'0',sizeof(mp));
		for(int i=10;i<n+10;i++){
			for(int j=10;j<m+10;j++)
				cin >>mp[i][j];
		}
		for(int i=0;i<n+20;i++)
			for(int j=0;j<m+20;j++){
				if(mp[i][j]=='0' && !vis[i][j])
					dfs(i,j,++cnt);
				if(mp[i][j]=='1'&& !vis1[i][j])
					dfs1(i,j,++cnt1);
			}
		if(cnt ==2 && cnt1==1)
			puts("0");
		else if(cnt==1 && cnt1==1)
			puts("1");
		else
			puts("-1");

	}

	return 0;
}
