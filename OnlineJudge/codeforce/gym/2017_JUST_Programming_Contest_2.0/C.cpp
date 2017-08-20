#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int m;
const int maxn=1e5+100,nmaxn=1e4+10;

int f[nmaxn][27];

string s[nmaxn];

struct Node{
	int v,cost;
	Node(int v,int cost):v(v),cost(cost){}
	Node(){}
};

struct Qnode{
	int c,v;
	Qnode(int v,int c):v(v),c(c){}
	bool operator<(const Qnode &r) const{
		return c > r.c;
	}
	Qnode(){}
};

vector<Node> mp[maxn];

bool vis[maxn];
int dist[maxn];


void Dij(int n,int start){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dist[i]=0x3f3f3f3f;
	priority_queue<Qnode> q;
	dist[start]=0;
	q.push(Qnode(start,0));
	Qnode tmp;
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		int u=tmp.v;
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=0;i<mp[u].size();i++){
			int v=mp[u][i].v;
			int cost=mp[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				q.push(Qnode(v,dist[v]));
			}
		}
	}
}

int _Cost(int u,int v)
{
	int ret=0;
	for(int i=0;i<26;i++){
		if(f[u][i] && f[v][i])
			ret++;
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
	for(int i=1;i<=n;i++){
		cin >> s[i];
		for(int j=0;j<s[i].size();j++){
			if(s[i][j] < 'a')
				f[i][s[i][j]-'A']=1;
			else
				f[i][s[i][j]-'a']=1;
		}
	}
	for(int v,u,i=0;i<m;i++){
		cin >> u >>v;
		int cost = _Cost(u,v);
		mp[u].push_back(Node(v,cost));
		mp[v].push_back(Node(u,cost));
	}
	int s,e;
	cin >> s >> e;
	Dij(n,s);
	cout << dist[e] << endl;
	return 0;
}
