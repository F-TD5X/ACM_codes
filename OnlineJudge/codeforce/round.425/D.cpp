#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int n,q;
vector<int> mp[maxn];
int fa[maxn][17],dep[maxn];

void dfs(int v=0){
	for(int i=1;i<17;i++)
		fa[v][i]=fa[fa[v][i-1]][i-1];
	for(auto u:mp[v]){
		dep[u]=dep[v]+1;
		fa[u][0]=v;
		dfs(u);
	}
}

int lca(int v,int u){
	if(dep[v]>dep[u])
		swap(v,u);
	for(int i=0;i<17;i++)
		if(dep[u] - dep[v] >> i & 1)
			u=fa[u][i];
	for(int i=16;i>=0;i--)
		if(fa[v][i]!=fa[u][i]){
			v=fa[v][i];u=fa[u][i];
		}
	return v==u?v:fa[v][0];
}

int solve(int f,int s,int t){
	int ret=0;
	bool i1=lca(f,s)==f,i2=lca(f,t)==f;
	if(i1!=i2)
		return 1;
	if(i1)
		ret=max(ret,dep[lca(s,t)]-dep[f]);
	else if(lca(f,s)!=lca(f,t))
		ret=max(ret,dep[f]-max(dep[lca(f,s)],dep[lca(f,t)]));
	else
		ret=max(ret,dep[f]+dep[lca(s,t)]-2*dep[lca(f,t)]);
	return ret+1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n >> q;
	for(int t,i=1;i<n;i++){
		cin >> t;
		t--;
		mp[t].push_back(i);
	}
	int a,b,c;
	dfs();
	while(q--){
		cin >> a >> b >>c;
		a--;b--;c--;
		cout <<solve(a,b,c) <<" "<<solve(b,a,c) <<" "<<solve(c,b,a)<<endl;
		cout << max({solve(a,b,c),solve(b,a,c),solve(c,b,a)})<<endl;
	}
	return 0;
}
