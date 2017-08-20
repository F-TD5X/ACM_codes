#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
vector<int> mp[maxn];
int N,M,Q;
int col[maxn];
int vis[maxn];
int v,d,c;

void dfs(int st,int dep,int color)
{
	if(dep==0)
		return;
	if(vis[st])
		return;
	vis[st]=1;
	col[st]=color;
	for(auto p:mp[st]){
		col[p]=color;
		dfs(p,dep-1,color);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
	while(cin >> N >> M){
		memset(col,0,sizeof(col));
		for(int i=1;i<=N;i++)
			mp[i].clear();
		for(int v,u,i=0;i<M;i++){
			cin >> v >> u;
			mp[v].push_back(u);
			mp[u].push_back(v);
		}
		cin >> Q;
		for(int v,d,c,i=0;i<Q;i++){
			cin >> v >> d >> c;
			memset(vis,0,sizeof(vis));
			dfs(v,d,c);
		}
		for(int i=1;i<=N;i++)
			cout << col[i] << endl;
	}
	return 0;
}
