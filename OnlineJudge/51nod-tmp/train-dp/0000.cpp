#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 555;
ll dp[maxn],ma[maxn][maxn],n,m;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("0000.in","r",stdin);
    //freopen("0000.out","w",stdout);
#endif
    cin >> m >> n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin >> ma[i][j];
    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                dp[k]=(j==i)?ma[i][k]:(dp[k]+ma[j][k]);
            }
        }
    ll ans =0;
    for(int i=1;i<=n;i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
