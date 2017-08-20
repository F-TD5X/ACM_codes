/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4;
int dp[111][maxn];
int w[maxn],c[maxn];
int n,m;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1085.in","r",stdin);
    //freopen("1085.out","w",stdout);
#endif
	cin >> n >> m;
	for(int p,pp,i=1;i<=n;i++)
		cin >> w[i] >>c[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++){
			if(j<w[i])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
		}
	cout << dp[n][m] << endl;
	return 0;
}
