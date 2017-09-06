/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=305;
char mp[maxn][maxn];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool vis[maxn][maxn];

void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int fx=x+dx[i],fy=y+dy[i];
		if(0 <= fx && fx <n && 0<=fy && fy<m)
			if(mp[fx][fy]!='W' && !vis[fx][fy])
				dfs(fx,fy);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("T.in","r",stdin);
    //freopen("T.out","w",stdout);
#endif
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> mp[i];
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]==0 && mp[i][j]=='L'){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout <<ans << endl;

	return 0;
}
