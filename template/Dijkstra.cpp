#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e3+10;
const int INF=0x3f3f3f3f;

int G[maxn][maxn];
int dis[maxn];
int pre[maxn];
bool vis[maxn];

void Dij(int start){
	int u;
	for(int i=0;i<=n;i++){
		dis[i] = G[start][i];
		vis[i] = 0;
	}
	vis[start]=1;dis[start]=0;
	for(int i=1;i<=n;i++){
		int min = INF;
		for(int j=1;j<=n;j++){
			if(!vis[j] && min > dis[j])
				min=dis[j],u=j;
		}
		if(min == INF) break;
		vis[u]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j] && G[u][j]!=INF && dis[u]+G[u][j] < dis[j])
				dis[j] = G[u][j]+dis[u],pre[j]=u;
		}
	}
}

int V;
struct edge{int to;int cost;};
vector<edge> G[maxn];
typedef pair<int,int> P;
int d[maxn];

void Dij_pq(int s){

	priority_queue<P,vector<P>,greater<P>> q;
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	q.push(P(0,s));
	while(!q.empty()){
		P p=q.top();
		q.pop();
		int v= p.second;
		if(d[v] < p.first) continue;
		for(int i=0;i<G[v].size();i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("Dijkstra.in","r",stdin);
    //freopen("Dijkstra.out","w",stdout);
#endif

    return 0;
}
