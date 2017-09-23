/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
const int maxn=1e5+10;
int val[maxn],head[maxn],cnt=0;
ll dp[maxn][2];
ll ans;
bool vis[maxn];

struct Edge{
	int to,val,next;
};

Edge G[maxn];

void init(){
	cnt=0;
	memset(vis,0,sizeof(vis));
	ans=-0x3f3f3f3f;
	memset(head,-1,sizeof head);
}

void addEdge(int from,int to,int v){
	G[cnt].val=val[to]-val[from]-v;
	G[cnt].to=to;
	G[cnt].next=head[from];
	head[from]=cnt++;
}

void dfs(int st,int pre){
	int v;
	vis[st]=1;
	dp[st][0]=dp[st][1]=0;
	for(int i=head[st];i!=-1;i=G[i].next){
		v=G[i].to;
		if(vis[v])
			continue;
		dfs(v,st);
		ll tmp=dp[v][1]+G[i].val;
		if(tmp > dp[st][1])
			swap(dp[st][1],tmp);
		if(tmp > dp[st][0])
			swap(dp[st][0],tmp);
	}
	ans=max(ans,dp[st][1]+dp[st][0]);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",val+i);
		}
		for(int u,v,w,i=0;i<n-1;i++){
			scanf("%d%d%d",&u,&v,&w);
			addEdge(u,v,w);
			addEdge(v,u,w);
		}
		dfs(1,-1);
		printf("%lld\n",ans);
	}

	return 0;
}
