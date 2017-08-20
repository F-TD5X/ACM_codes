<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=6666;
int n;
vector<int> tree[maxn];
int dp[maxn][2],fa[maxn];

void dfs(int st){
	for(auto v:tree[st])
		dfs(v);
	for(auto v:tree[st]){
		dp[st][0]+=max(dp[v][0],dp[v][1]);
		dp[st][1]+=dp[v][0];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1520.in","r",stdin);
    //freopen("1520.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int i=0;i<=n;i++)
			tree[i].clear();
		memset(dp,0,sizeof(dp));
		memset(fa,-1,sizeof(fa));
		for(int i=1;i<=n;i++)
			scanf("%d",&dp[i][1]);
		for(int u=-1,v=-1;u+v;){
			scanf("%d%d",&u,&v);
			tree[v].push_back(u);
			fa[u]=v;
		}
		int root=1;
		while(fa[root]!=-1) root=fa[root];
		dfs(root);
		cout << max(dp[root][1],dp[root][0])<<endl;



	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=6666;
int n;
vector<int> tree[maxn];
int dp[maxn][2],fa[maxn];

void dfs(int st){
	for(auto v:tree[st])
		dfs(v);
	for(auto v:tree[st]){
		dp[st][0]+=max(dp[v][0],dp[v][1]);
		dp[st][1]+=dp[v][0];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1520.in","r",stdin);
    //freopen("1520.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int i=0;i<=n;i++)
			tree[i].clear();
		memset(dp,0,sizeof(dp));
		memset(fa,-1,sizeof(fa));
		for(int i=1;i<=n;i++)
			scanf("%d",&dp[i][1]);
		for(int u=-1,v=-1;u+v;){
			scanf("%d%d",&u,&v);
			tree[v].push_back(u);
			fa[u]=v;
		}
		int root=1;
		while(fa[root]!=-1) root=fa[root];
		dfs(root);
		cout << max(dp[root][1],dp[root][0])<<endl;



	}
	return 0;
}
>>>>>>> 15efef77bd5e792465c034dce28c633a41daf492
