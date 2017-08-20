/*Author NoZuoNoDieWhyITry*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
int n;
const int maxn=1510;
vector<int> mp[maxn];
int dp[maxn][2];
bool vis[maxn];
int fa[maxn];

void solve(int st){
	int ret=0;
	vis[st]=1;
	dp[st][0]=0;dp[st][1]=1;
	for(int i=0;i<mp[st].size();i++){
		if(!vis[mp[st][i]]){
			solve(mp[st][i]);
			dp[st][0]+=dp[mp[st][i]][1];
			dp[st][1]+=min(dp[mp[st][i]][1],dp[mp[st][i]][0]);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("poj_1463.in","r",stdin);
    //freopen("poj_1463.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int i=0;i<=n;i++)
			mp[i].clear();
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		memset(fa,-1,sizeof(fa));
		for(int u,t,v,i=0;i<n;i++){
			scanf("%d:(%d)",&u,&t);
			for(int j=0;j<t;j++){
				scanf("%d",&v);
				mp[u].push_back(v);
				fa[v]=u;
			}
		}
		int root=1;
		while(fa[root]!=-1)
			root=fa[root];
		solve(root);
		printf("%d\n",min(dp[root][1],dp[root][0]));
	}
	return 0;
}
