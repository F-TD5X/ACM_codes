#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FI first
#define SE second
int n,m;
char mp[222][222];
int ans;
int xx,yy,x2,y2;
vector<pair<int,int>> v;
int vis[222][222];
int cnt[2][222][222];

struct Node
{
	int x,y,step;
	Node(){}
	Node(int x,int y,int step):x(x),y(y),step(step){}
};

int bfs(int x,int y,int id)
{
	memset(vis,0,sizeof(vis));
	queue<Node> q;
	q.push(Node(x,y,0));
	Node st;
	int ret1=0,ret2=0;
	while(!q.empty())
	{
		st=q.front();
		q.pop();
		if(vis[st.x][st.y] || mp[st.x][st.y]=='#' ||(st.x < 0 || st.x>=n ||st.y<0 || st.y>=m))
			continue;
		vis[st.x][st.y]=1;
		if(mp[st.x][st.y]=='@')
			cnt[id][st.x][st.y]=st.step;
		q.push(Node(st.x+1,st.y,st.step+1));
		q.push(Node(st.x,st.y+1,st.step+1));
		q.push(Node(st.x-1,st.y,st.step+1));
		q.push(Node(st.x,st.y-1,st.step+1));
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("K.in","r",stdin);
    //freopen("K.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m))
	{
		v.clear();
		memset(cnt,0x3f3f3f3f,sizeof(cnt));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf(" %c" ,&mp[i][j]);
				if(mp[i][j]=='M'){
					xx=i;yy=j;
				}
				if(mp[i][j]=='Y'){
					x2=i;y2=j;
				}
			}
		}
		ans=1e9;
		bfs(xx,yy,0);
		bfs(x2,y2,1);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{	
				ans=min(ans,cnt[0][i][j]+cnt[1][i][j]);
			}
		printf("%d\n",ans*11);
	}
	return 0;
}

