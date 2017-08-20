<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,y,m;
const int maxn=20;
int mp[maxn][maxn],vis[maxn];
vector<int> ans;

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u]=1;
	for(int i=1;i<=n;i++)
		dfs(u);
	ans.push_back(u);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	while(~scanf("%d%d%d",&n,&y,&m)){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		ans.clear();
		for(int u,v,i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			mp[u][v]=1;
		}
		for(int i=1;i<=n;i++)
			dfs(i);
		for(auto a:ans)
			cout << a<< " ";
		cout << endl;
	}	
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,y,m;
const int maxn=20;
int mp[maxn][maxn],vis[maxn];
vector<int> ans;

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u]=1;
	for(int i=1;i<=n;i++)
		dfs(u);
	ans.push_back(u);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	while(~scanf("%d%d%d",&n,&y,&m)){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		ans.clear();
		for(int u,v,i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			mp[u][v]=1;
		}
		for(int i=1;i<=n;i++)
			dfs(i);
		for(auto a:ans)
			cout << a<< " ";
		cout << endl;
	}	
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,y,m;
const int maxn=20;
int mp[maxn][maxn],vis[maxn];
vector<int> ans;

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u]=1;
	for(int i=1;i<=n;i++)
		dfs(u);
	ans.push_back(u);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	while(~scanf("%d%d%d",&n,&y,&m)){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		ans.clear();
		for(int u,v,i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			mp[u][v]=1;
		}
		for(int i=1;i<=n;i++)
			dfs(i);
		for(auto a:ans)
			cout << a<< " ";
		cout << endl;
	}	
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
