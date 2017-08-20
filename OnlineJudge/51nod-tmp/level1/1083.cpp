#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int maxn=555;
int n;
int v[maxn][maxn];
ll dp[maxn][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1083.in","r",stdin);
    //freopen("1083.out","w",stdout);
#endif
    memset(dp,0,sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> v[i][j];
    dp[1][1]=v[1][1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+v[i][j];
        }
    cout <<dp[n][n]<<endl;
    return 0;
}
