#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9
const int maxn=300;
int n,T,t[maxn],M1,d1[maxn],Mn,dn[maxn];
int has_train[maxn][maxn][2];
int dp[maxn][maxn];
int cas;
void solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<n;i++)
		dp[T][i]=INF;
	dp[T][0]=0;
	for(int i=T-1;i>=0;i--)
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i+1][j]+1;
			if(j<n && has_train[i][j][0] && i+t[j]<=T)
				dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
			if(j>1 && has_train[i][j][1] && i+t[j-1]<=T)
				dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
		}
	printf("Case Number %d: ",cas);
	if(dp[0][1] >=INF)
		cout <<"impossible"<<endl;
	else
		cout <<dp[0][1]<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("UVa1025.in","r",stdin);
    //freopen("UVa1025.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&T) && n)
	{
		cas++;
		int p;
		memset(has_train,0,sizeof(has_train));
		for(int i=1;i<=n-1;i++) scanf("%d",t+i);
		scanf("%d",&M1);
		while(M1--)
		{
			scanf("%d",&p);
			for(int j=1;j<=n-1;p+=t[j],j++)
				if(p<=T)
					has_train[p][j][0]=1;
				else 
					break;
		}
		scanf("%d",&Mn);
		while(Mn--)
		{
			scanf("%d",&p);
			for(int j=n-1;j>=1;p+=t[j],j--)
				if(p<=T)
					has_train[p][j+1][1]=1;
				else 
					break;
		}
		solve();
	}
	return 0;
}
