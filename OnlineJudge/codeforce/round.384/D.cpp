#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
ll a[maxn];
vector<int> mp[maxn];
ll sum[maxn];
bool vis[maxn];
int n;
ll ans;

void dfs(int v)
{
	vis[v]=1;
	sum[v]=a[v];
	a[v]=-INF;
	ll m1=-INF,m2=-INF;
	for(int u:mp[v])
	{
		if(vis[u])
			continue;
		dfs(u);
		sum[v]+=sum[u];
		ll val=a[u];
		a[v]=max(a[v],val);
		if(m1<val)
			swap(m1,val);
		if(m2<val)
			swap(m2,val);
	}
	if(m2>-INF)
		ans=max(ans,m1+m2);
	a[v]=max(a[v],sum[v]);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n;
	ans=-INF;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int u,v,i=0;i<n-1;i++)
	{
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1);
	if(ans==-INF)
		puts("Impossible");
	else
		cout <<ans<<endl;
	return 0;
}
