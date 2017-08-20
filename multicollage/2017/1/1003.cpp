/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+100;
int T;
int n,m;
vector<int> mp[maxn];
ll c[maxn],sum[maxn],size[maxn];
bool visc[maxn];
bool vis[maxn];
ll cnt=0;
ll d,len;

void dfs(int v,int fa){
	if(vis[v])
		return;
	ll pre=sum[c[v]];
	vis[v]=1;
	size[v]=1;
	ll add=0;
	for(auto u:mp[v]){
		if(u==fa)
			continue;
		dfs(u,v);
		size[v]+=size[u];
		ll cnt1=size[u]-sum[c[v]]+pre;
		pre=sum[c[v]];
		add+=cnt1;
		d+=cnt1*(cnt1-1)/2;
	}
	sum[c[v]]+=add+1;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif
	int kase=1;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			mp[i].clear();
		memset(visc,0,sizeof(visc));
		memset(vis,0,sizeof(vis));
		memset(sum,0,sizeof(sum));
		d=len=cnt=0;

		for(int i=1;i<=n;i++){
			scanf("%d",c+i);
			if(!visc[c[i]]){
				visc[c[i]]=1;
				cnt++;
			}
		}
		for(int v,u,i=1;i<n;i++){
			scanf("%d%d",&v,&u);
			mp[v].push_back(u);
			mp[u].push_back(v);
		}
		dfs(1,0);
		ll ans=(cnt*(n-1)*n/2)-d;
		for(int i=1;i<=n;i++)
			if(visc[i]&&i!=c[1]){
				ll cnt1=n-sum[i];
				ans-=cnt1*(cnt1-1)/2;
			}
		printf("Case #%d: %lld\n",kase++,ans);
	}

	return 0;
}
