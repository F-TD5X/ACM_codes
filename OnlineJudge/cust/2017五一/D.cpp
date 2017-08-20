#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int T;
int kase=1;
const int maxn=(1<<20) +10;
int dp[41][maxn];
int v[41];
int cnt;

int dodp()
{
	int a=1<<cnt;
	for(int i=0;i<n;i++)
		for(int j=0;j<a;j++)
			dp[i][j]=0;
	dp[0][0]=dp[0][v[0]]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<a;j++)
		{
			dp[i][j]+=dp[i-1][j];
			dp[i][j^v[i]]+=dp[i-1][j];
		}
	}
	ll ans=0;
	for(int i=m;i<a;i++)
	{
		ans+=dp[n-1][i];
	}
	printf("Case #%d: %lld\n",kase++,ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> T;
	while(T--)
	{
		int ma=0;
		cin >> n >> m;
		for(int i=0;i<n;i++){
			cin >> v[i];
			ma=max(ma,v[i]);
		}
		cnt=0;
		while(ma)
		{
			cnt++;
			ma/=2;
		}
		dodp();
	}

	return 0;
}
