/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x;
const int maxn=2e5+100;
vector<int> mp[maxn];
int dep[maxn];
int dis;
vector<int> l;
bool flag=0;
int vis[maxn];


int dfs(int v)
{
	if(vis[v])
		return dep[v];
	vis[v]=1;
	int ret=0;
	if(mp[v].size()==0)
		dep[v]=ret=0;
	if(v==x){
		l.push_back(v);
		flag=1;
	}
	for(auto u:mp[v]){
		if(vis[u])
			continue;
		if(!flag)
			l.push_back(v);
		ret=max(dfs(u)+1,ret);
		if(!flag)
			l.pop_back();
	}
	dep[v]=ret;
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n >> x;
	for(int v,u,i=1;i<n;i++){
		cin >> v >> u;
		mp[v].push_back(u);
		mp[u].push_back(v);
	}
	dfs(1);
	dis=(l.size()-1)/2;
	int ans=l.size()-1+dep[x];
	for(int i=0,j=l.size()-1;i<dis;i++,j--){
		ans=max(ans,(int)l.size()-1+dep[l[j]]);
	}
	cout << ans*2 << endl;
	return 0;
}
