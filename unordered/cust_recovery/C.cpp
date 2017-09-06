/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=60,INF=0x3f3f3f3f;
char mp[maxn][maxn];
bool vis[maxn][maxn][maxn];
int dp[maxn][maxn][maxn];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
map<char,int> d;
char cmd[maxn];
int sx,sy,ex,ey;

struct Node{
	int x,y,id;
};

int spfa(){
	int ret=INF;
	memset(dp,INF,sizeof dp);
	queue<Node> q;
	dp[sx][sy][0]=0;
	q.push({sx,sy,0});
	Node t;
	while(!q.empty()){
		t=q.front();q.pop();
		vis[t.x][t.y][t.id]=0;
		if(mp[t.x][t.y]=='E'){
			ret=min(ret,dp[t.x][t.y][t.id]);
			continue;
		}
		for(int i=0;i<4;i++){
			int fx=t.x+d[i],fy=t.y+dy[i];
			if(fx<1 || fx>n || fx<1 || fy>m || mp[fx][fy]=='#'){
				if(d[cmd[t.id]]==i){
					if(dp[t.x][t.y][t.id]<dp[t.x][t.y][t.id+1]){
						dp[t.x][t.y][t.id+1]=dp[t.x][t.y][t.id];
						if(!vis[t.x][t.y][t.id+1]){
							vis[t.x][t.y][t.id+1]=1;
							q.push({t.x,t.y,t.id+1});
						}
					}
				}
				continue;
			}
			int ans=dp[t.x][t.y][t.id];
			int fid=t.id;
			if(d[cmd[t.id]]==i)
				fid++;
			else 
				ans++;
			if(ans < dp[fx][fy][fid]){
				dp[fx][fy][fid]=ans;
				if(!vis[fx][fy][fid]){
					vis[fx][fy][fid]=1;
					q.push({fx,fy,fid});
				}
			}
		}
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n >> m;
	d['U']=0;d['D']=1;d['L']=2;d['R']=3;
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='R')
				sx=i,sy=j;
			if(mp[i][j]=='E')
				ex=i,ey=j;
		}
	}
	cin >> cmd;
	cout << spfa()<<endl;
	return 0;
}
