#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 17, lmp = 17;


vector<int> mp[maxn];
int n, q, fa[maxn][lmp], dep[maxn], ver[3];
void dfs(int v = 0){
	for(int i = 1; i < lmp; i++)
		fa[v][i] = fa[ fa[v][i - 1] ][i - 1];
	for(auto u : mp[v]){
		dep[u] = dep[v] + 1;
		fa[u][0] = v;
		dfs(u);
	}
}
int lca(int v, int u){
	if(dep[v] > dep[u])  swap(v, u);
	for(int i = 0; i < lmp; i++)
		if(dep[u] - dep[v] >> i & 1)
			u = fa[u][i];
	for(int i = lmp - 1; i >= 0; i--)
		if(fa[v][i] != fa[u][i])
			v = fa[v][i], u = fa[u][i];
	return v == u ? v : fa[v][0];
}
int solve(int f, int s, int t){
	int ans = 0;
	bool is1 = lca(f, s) == f, is2 = lca(f, t) == f;
	if(is1 != is2)  return 1;
	if(is1)
		ans = max(ans, dep[ lca(s, t) ] - dep[ f ]);
	else if(lca(f, s) != lca(f, t))
		ans = max(ans, dep[ f ] - max(dep[ lca(f, s) ], dep[ lca(f, t) ]));
	else
		ans = max(ans, dep[ f ] + dep[ lca(s, t) ] - 2 * dep[ lca(f, t) ]);
	return ans + 1;
}
int main(){
	cin >> n >> q;
	for(int i = 1, p; i < n; i++){
		cin >> p, p--;
		mp[p].push_back(i);
	}
	dfs();
	while(q--){
		for(int i = 0; i < 3; i++)
			cin >> ver[i], ver[i]--;
		cout << max({solve(ver[0], ver[1], ver[2]), solve(ver[1], ver[0], ver[2]), solve(ver[2], ver[1], ver[0])}) << '\n';
	}
	return 0;
}
