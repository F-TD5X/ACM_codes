#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int maxn=555;
int n;
int mp[maxn][maxn];
int dp[maxn][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1002.in","r",stdin);
    //freopen("1002.out","w",stdout);
#endif
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin >> mp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i][j]=max(dp[i-1][j-1]+mp[i][j],dp[i-1][j]+mp[i][j]);
    int ans=0;
    for(int i=0;i<=n;i++)
        ans=max(ans,dp[n][i]);
    cout <<ans <<endl;
    return 0;
}
