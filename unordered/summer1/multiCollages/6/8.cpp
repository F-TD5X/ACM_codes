#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1e3+10;
const int mod = 1e9+7;
using namespace std;
int dp[maxn][maxn][3][3];
int a[maxn],T,n,m;
ll ans;

int main()
{
#ifndef ONLINE_JUDGE
        freopen("1008.in","r",stdin);
        freopen("1008","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=m;j>=0;j--)
                for(int k=2;k>=0;k--)
                    for(int q=2;q>=0;q--)
                    {
                        dp[i][j][k][q]=(dp[i][j][k][q]+dp[i-1][j][k][q])%mod;
                        if(j+a[i] <=m)
                            dp[i][j+a[i]][k][q]=(dp[i][j+a[i]][k][q]+dp[i-1][j][k][q])%mod;
                        if(k>0 && j+a[i] <=m) 
                            dp[i][j+a[i]][k][q]=(dp[i][j+a[i]][k][q]+dp[i-1][j][k-1][q])%mod;
                        if(q>0)
                            dp[i][j][k][q]=(dp[i][j][k][q]+dp[i-1][j][k][q-1])%mod;
                    }
        ans = 0;
        for(int i=2;i<=m;i++)
            ans += dp[n][i][2][2];
        cout << (ans%mod*2*2)%mod << endl;
    }
    return 0;
}
