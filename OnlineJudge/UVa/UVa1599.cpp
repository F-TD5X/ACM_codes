#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	int x,d;
	Node(int x=0,int d=0):x(x),d(d){}
};
int n,m;
const int maxn=1e5+10;
vector<int> mp[maxn];
map<int,string>v[maxn];
int d[maxn],vis[maxn];
vector<string>ans;

void bfs1()
{
	queue<Node>q;
	q.push(Node(n,0));
	vis[n]=1;
	Node t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		vis[t.x]=1;
		if(t.x==1)
			return;
		for(auto u:mp[t.x])
		{
			if(vis[u])
				continue;
			q.push(Node(u,t.d+1));
			if(d[u]==0)
				d[u]=t.d+1;
			else
				d[u]=min(d[u],t.d+1);
		}
	}
}

void bfs2()
{
	queue<int>q;
	q.push(1);
	int t;
	vis[1]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		vis[t]=1;
		int p=-1;
		if(t == n)
			return;
		for(auto u:mp[t])
		{
			if(vis[u])
				continue;
			if(p==-1 && d[u]+1 == d[t])
				p=u;
			else if(v[t][u]<v[t][p] && d[u]+1==d[t])
				p=u;
		}
		if(p!=-1)
		{
			q.push(p);
			ans.push_back(v[t][p]);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa1599.in","r",stdin);
    //freopen("UVa1599.out","w",stdout);
#endif
	while(cin >> n >> m)
	{
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++)
		{
			mp[i].clear();
			v[i].clear();
		}
		int a,b;
		string c;
		for(int i=0;i<m;i++)
		{
			cin >>a >>b >>c;
			mp[a].push_back(b);
			mp[b].push_back(a);
			v[a][b]=v[b][a]=c;
		}
		memset(vis,0,sizeof(vis));
		bfs1();
		memset(vis,0,sizeof(vis));
		ans.clear();
		bfs2();
		cout << ans.size()<<endl;
		for(auto a:ans)
			cout <<a << " ";
		cout <<endl;
	}
	return 0;
}
