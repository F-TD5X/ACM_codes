#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll dp[1111][1111];
int n,m;
const int mod =1e9+7;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1118.in","r",stdin);
    //freopen("1118.out","w",stdout);
#endif
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        dp[i][1]=1;
    for(int i=1;i<=m;i++)
        dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
    cout << dp[n][m]<<endl;
    return 0;
}
