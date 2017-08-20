/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1010;
ll dp[maxn];
int n;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1031.in","r",stdin);
    //freopen("1031.out","w",stdout);
#endif
	cin >> n;
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++)
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	cout <<dp[n]<<endl;

	return 0;
}
