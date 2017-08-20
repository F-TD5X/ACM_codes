#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=1111;
int a[maxn],b[maxn],dp[maxn][maxn];
const int INF=0x3f3f3f3f;

int dfs(int l,int r)
{
	if(l>r)
		return 0;
	if(l==r)
		return dp[l][r]=a[l]+b[l-1]+b[l+1];
	if(dp[l][r]!=INF)
		return dp[l][r];
	dp[l][r]=INF;
	for(int k=l;k<=r;k++)
		dp[l][r]=min(dp[l][r],dfs(l,k-1)+dfs(k+1,r)+a[k]+b[l-1]+b[r+1]);
	return dp[l][r];
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int T;
	cin >> T;
	int kase=1;
	while(T--)
	{
		cin >> n;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=INF;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		dfs(1,n);
		printf("Case #%d: %d\n",kase++,dp[1][n]);
	}
	return 0;
}
