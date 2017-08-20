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
const int maxn=6666;
int dp[maxn][2];
vector<int> mp[maxn];

bool vis[maxn];

void dfs(int st){
	vis[st]=1;
	for(int i=0;i<mp[st].size();i++){
		int &v=mp[st][i];
		if(!vis[v]){
			dfs(v);
			dp[st][1]+=dp[v][0];
			dp[st][0]+=max(dp[v][1],dp[v][0]);
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("POJ_2342.in","r",stdin);
    //freopen("POJ_2342.out","w",stdout);
#endif
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<=n;i++)
			mp[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&dp[i][1]);
		int l,k,root=0;
		while(~scanf("%d%d",&l,&k) && l+k){
			mp[k].push_back(l);
			root=k;
		}
		memset(vis,0,sizeof(vis));
		dfs(root);
		printf("%d\n",max(dp[root][0],dp[root][1]));
	}
	return 0;
}

