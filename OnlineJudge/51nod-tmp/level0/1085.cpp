#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int dp[111][11111],n,m,v[111],p[111];;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1085.in","r",stdin);
    //freopen("1085.out","w",stdout);
#endif
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> v[i] >> p[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j<v[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+p[i]);
        }
    }
    cout << dp[n][m]<<endl;
    return 0;
}
