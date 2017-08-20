#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,m,k;
const int maxn = 111;
ll dp[maxn][maxn][maxn];
int c[maxn];
ll cost[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
    cin >> n >>m>>k;
    for(int i=1;i<=n;i++)
        cin >> c[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int p=0;p<=m;p++)
                dp[i][j][p]=ll(1e18);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> cost[i][j];
    if(c[1]==0)
        for(int i=1;i<=m;i++)
            dp[1][1][i]=cost[1][i];
    else
        dp[1][1][c[1]]=0;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=k;j++)
            if(c[i]==0)
            {
                for(int p=1;p<=m;p++)
                {
                    dp[i][j][p]=min(dp[i][j][p],dp[i-1][j][p]+cost[i][p]);
                    for(int t=1;t<=m;t++)
                    {
                        if(t!=p)
                            dp[i][j][p]=min(dp[i][j][p],dp[i-1][j-1][t]+cost[i][p]);
                    }
                }
            }
            else
            {
                dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j][c[i]]);
                for(int p=1;p<=m;p++)
                {
                    if(p!=c[i])
                        dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j-1][p]);
                }
            }
    ll ans = ll(1e18);
    for(int i=1;i<=m;i++)
        ans = min(ans,dp[n][k][i]);
    if(ans >=ll(1e18))
        puts("-1");
    else
        cout << ans << endl;
    return 0;
}
