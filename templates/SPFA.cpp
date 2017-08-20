const int maxn=1e4+10;

struct SPFA{
	struct Edge{
		int from,to,dist;
	};
	int d[maxn],cnt[maxn],p[maxn];
	int n,m;
	bool inq[maxn];
	vector<int> G[maxn];
	vector<Edge> edges;
	int path[maxn];			//记录最短路

	void init(int n){
		this->n=n;
		for(int i=1;i<=n;i++) G[i].clear();
		edges.clear();
	}

	void Add_edge(int from,int to,int dist){
		edges.push_back(Edge(from,to,dist));
		int m=edges.size();
		G[from].push_back(m-1);
	}

	bool spfa(int s){
		memset(d,INF,sizeof(d));
		memset(cnt,0,sizeof(cnt));
		memset(inq,0,sizeof(inq));
		queue<int> q;
		q.push(s);
		inq[s]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			inq[u]=1;
			for(int i=0;i<G[u].size();i++){
				Edge &e=edges[G[u][i]];
				if(d[e.to]> d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					path[e.to]=u;
					p[e.to]=G[u][i];
					if(!inq[e.to]){
						q.push(e.to);inq[e.to]=1;
						if(++cnt[e.to] > n)
							return false;
					}
				}
			}
		}
		return 1;
	}

	void printpath(int k){
		if(path[k]!=0)
			printpath(path[k]);
		printf("%d ",k);
	}
}
