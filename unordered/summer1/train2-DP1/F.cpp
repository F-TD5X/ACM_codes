#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn= 1010;
const int mod=1000000007;
char s[maxn];
int dp[maxn][maxn],ans,len;

int main()
{
    while(cin >>s)
    {
        len = strlen(s)+1;
        memset(dp,0,sizeof(dp));
        dp[1][1]=1;
        ans =0;
        for(int i=2;i<len;i++)
        {
            char c = s[len-i];
            if(c =='?')
            {
                for(int j= 1;j<i;j++)
                {
                    dp[i][1]+=dp[i-1][j];
                    dp[i][1]%=mod;
                }
                for(int j=2;j<=i;j++)
                    dp[i][j] = dp[i][j-1];
            }
            else if( c=='D')
            {
                for(int j=2;j<=i;j++)
                {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                    dp[i][j]%=mod;
                }
            }
            else
            {
                for(int j=i-1;j>=0;j--)
                {
                    dp[i][j] = dp[i][j+1] + dp[i-1][j];
                    dp[i][j] %=mod;
                }
            }
        }
        for(int i=1;i<=len;i++)
        {
            ans += dp[len-1][i];
            ans %=mod;
        }
        cout  << ans << endl;
    }
}

