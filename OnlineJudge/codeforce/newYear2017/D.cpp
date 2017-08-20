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

int mp[333][333]; // is the map truly no bigger than 300*300? I guess yes...
int vis[333][333][33][8];
int dx[]={0,1,1,1,0,-1,-1,-1},dy[]={1,1,0,-1,-1,-1,0,1};
int len[33];
int T;

void dfs(int x,int y,int dep,int dir)
{
	if(vis[x][y][dep][dir]) return;
	vis[x][y][dep][dir]=1;
	for(int i=0;i<len[dep];i++)
	{
		x+=dx[dir];
		y+=dy[dir];
		mp[x][y]=1;
	}
	if(dep!=T-1)
	{
		dfs(x,y,dep+1,(dir+1)%8);
		dfs(x,y,dep+1,(dir+7)%8);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >>T;
	for(int i=0;i<T;i++)
		cin >> len[i];
	len[0]--;
	mp[155][155]=1;
	dfs(155,155,0,0);
	int ans=0;
	for(int i=0;i<333;i++)
		for(int j=0;j<333;j++)
			ans+=mp[i][j];
	cout <<ans << endl;
	return 0;
}
