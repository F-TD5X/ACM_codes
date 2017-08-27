/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
#define FI first
#define SE second
using namespace std;
typedef long long ll;
int T,n,m;
const int maxn=1e5+10,INF=0x3f3f3f3f;
ll d[maxn][2],tot;

struct Node{
	int u;
	ll d;
	Node(ll d=0,int u=0):d(d),u(u){}
	bool operator<(const Node &t) const{
		return d>t.d;
	}
};

struct Edge{
	ll w;
	int to;
	Edge(int to,ll w):to(to),w(w){}
};

vector<int> mp[maxn];
vector<Edge> E;

int dij(){
	priority_queue<Node> Q;
    Q.push(Node(0,1));
    d[1][0] = 0;
    while(!Q.empty())
    {
        Node x = Q.top(); Q.pop();
        int u = x.u;
        if(d[u][1] < x.d) continue;
        for(int i = 0; i < mp[u].size(); i++)
        {
            Edge& e = E[mp[u][i]];
            ll dis = x.d + e.w;
            if(d[e.to][0] > dis)
            {
                d[e.to][1] = d[e.to][0];
                d[e.to][0] = dis;
                Q.push(Node(dis,e.to));
            }
            else if(d[e.to][1] > dis)
            {
                d[e.to][1] = dis;
                Q.push(Node(dis,e.to));
            }
        }
    }
}

void addEdge(int a,int b,ll w)
{
    E.push_back(Edge(b,w));
    mp[a].push_back(tot++);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			mp[i].clear();
		E.clear();
		memset(d,INF,sizeof(d));
		tot=0;
		for(int u,v,i=0;i<m;i++){
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			addEdge(u,v,w);
			addEdge(v,u,w);
		}
		dij();
		cout << d[n][1] << endl;
	}
	return 0;
}
