#include<bits/stdc++.h>
using namespace std;
const int mod= 1e9+7;
int n,m,a[1111],b[1111],dp[1111][1111],sum[1111][1111],sum1[1111][1111];
int ans = 0;
int main()
{

    while(cin >> n >> m)
    {
        ans =0;
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        memset(sum1,0,sizeof(sum1));
        for(int i=1;i<=n;i++)
            cin >> a[i];
        for(int i=1;i<=m;i++)
            cin >> b[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i] == b[j])
                {
                    dp[i][j] = (sum1[i-1][j-1]+1)%mod;
                    sum[i][j] = (sum[i-1][j] + dp[i][j])%mod;
                    sum1[i][j] = (sum1[i][j-1] + sum[i][j])%mod;
                }
                else
                {
                    sum[i][j] = sum[i-1][j];
                    sum1[i][j] = (sum1[i][j-1] +sum[i][j])%mod;
                }
            }
        }
        for(int i= 1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans = (ans + dp[i][j])%mod;
        cout << ans <<endl;
    }
}
