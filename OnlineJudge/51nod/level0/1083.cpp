/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=555;
int n,m;
int mp[maxn][maxn];
int dp[maxn][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1083.in","r",stdin);
    //freopen("1083.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mp[i][j];
	cout << dp[n][n]<<endl;

	return 0;
}
