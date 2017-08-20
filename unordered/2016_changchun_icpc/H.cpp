#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3000;
int n,f[maxn],dp[maxn];
ll ans=0;
const int inf=0x3f3f3f;

int dodp()	//排除最后一个点
{
	for(int i=0;i<=n;i++)
		dp[i]=-inf;
	dp[0]=0;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j+i-1<=n-2;j++)
			dp[i+j-1]=max(dp[i+j-1],dp[j]+f[i]);
	}
	return dp[n-2];
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
	int t;
	cin >>t;
	while(t--)
	{
		cin >> n;
		for(int i=1;i<n;i++)
			cin >> f[i];
		ans=f[1]*n;	//度为1
		for(int i=2;i<n;i++)
			f[i]-=f[1];		//满足操作的+和-
		cout << ans+dodp() << endl;		//求dp结果
	}
	return 0;
}
