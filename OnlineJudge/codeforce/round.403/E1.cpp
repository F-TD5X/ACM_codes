<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
const int maxn=2e5+100;
vector<int> mp[maxn],ans;
bool vis[maxn];

int dfs(int now)
{
	ans.push_back(now);
	vis[now]=1;
	for(auto a:mp[now]) {
		if(!vis[a]) {
			dfs(a);
			ans.push_back(now);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E1.in","r",stdin);
    //freopen("E1.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int u,v,i=0;i<m;i++) {
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1);
	for(int i = 1,c = 0;i <= k;i ++)
	{
		if (c == ans.size()) 
			printf("1 1\n");
	   	else
		{
			int l = min(int(ceil(2.0 * n / k)),int(ans.size()) - c);
			printf("%d", l);
			for(;l;l --,++ c) 
				printf(" %d", ans[c]);
			printf("\n");
		}
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
const int maxn=2e5+100;
vector<int> mp[maxn],ans;
bool vis[maxn];

int dfs(int now)
{
	ans.push_back(now);
	vis[now]=1;
	for(auto a:mp[now]) {
		if(!vis[a]) {
			dfs(a);
			ans.push_back(now);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E1.in","r",stdin);
    //freopen("E1.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int u,v,i=0;i<m;i++) {
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1);
	for(int i = 1,c = 0;i <= k;i ++)
	{
		if (c == ans.size()) 
			printf("1 1\n");
	   	else
		{
			int l = min(int(ceil(2.0 * n / k)),int(ans.size()) - c);
			printf("%d", l);
			for(;l;l --,++ c) 
				printf(" %d", ans[c]);
			printf("\n");
		}
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
