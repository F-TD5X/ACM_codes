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


struct Node
{
	int x,y,step;
	Node(){}
	Node(int x,int y,int step):x(x),y(y),step(step){}
};

int bfs(int x,int y)
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
		if(ret1+st.step >ans || ret2+st.step >ans)
			continue;
		vis[st.x][st.y]=1;
		if(st.x==xx && st.y== yy)
			ret1=st.step;
		if(st.x==x2 && st.y==y2)
			ret2=st.step;
		if(ret1 && ret2){
			return ret1+ret2;
		}
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
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(mp[i][j]=='@')
					ans=min(ans,bfs(i,j));
		printf("%d\n",ans*11);
	}
	return 0;
}
