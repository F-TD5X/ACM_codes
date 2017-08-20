<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
vector<int> mp[maxn];
int vis[maxn],color[maxn],ma;
int n;

void dfs(int u,int pre)
{
	int c=1;
	for(auto v:mp[u])
	{
		if(v!=pre)
		{
			//cout << v << " " << u << " " << pre << " " << c<<endl;
			while(c==color[u] || c==color[pre]) c++;
			color[v]=c;
			c++;
		}
	}
	for(auto v:mp[u])
		if(v!=pre)
			dfs(v,u);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin>>n;
	for(int u,v,i=1;i<n;i++)
	{
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	color[1]=1;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ma=max(ma,color[i]);
	cout << ma << endl;
	for(int i=1;i<=n;i++)
		cout << color[i] <<" ";
	cout << endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
vector<int> mp[maxn];
int vis[maxn],color[maxn],ma;
int n;

void dfs(int u,int pre)
{
	int c=1;
	for(auto v:mp[u])
	{
		if(v!=pre)
		{
			//cout << v << " " << u << " " << pre << " " << c<<endl;
			while(c==color[u] || c==color[pre]) c++;
			color[v]=c;
			c++;
		}
	}
	for(auto v:mp[u])
		if(v!=pre)
			dfs(v,u);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin>>n;
	for(int u,v,i=1;i<n;i++)
	{
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	color[1]=1;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ma=max(ma,color[i]);
	cout << ma << endl;
	for(int i=1;i<=n;i++)
		cout << color[i] <<" ";
	cout << endl;
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
