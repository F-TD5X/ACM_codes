#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=11111;
int T,n,V;
ll c[maxn],v[maxn];
ll dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("hdu-2602.in","r",stdin);
    //freopen("hdu-2602.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&V);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			scanf("%d",c+i);
		for(int i=1;i<=n;i++)
			scanf("%d",v+i);
		for(int i=1;i<=n;i++)
			for(int j=V;j>=c[i];j--)
				dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
		printf("%d\n",dp[V]);
	}
	return 0;
}
