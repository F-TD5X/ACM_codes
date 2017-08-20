#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn=1111;
const int mod=1000000007;

char s[maxn];
ll dp[maxn][maxn],sum[maxn][maxn];

int main()
{
    while(scanf("%s",s+2)!=EOF)
    {
        int len = strlen(s+2)+1;
        sum[1][1]=dp[1][1]=1;
        for(int i=2;i<=len;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(s[i]=='I')
                    dp[i][j] = sum[i-1][j-1];
                else if(s[i] == 'D')
                    dp[i][j] = sum[i-1][i-1]-sum[i-1][j-1];
                else 
                    dp[i][j] = sum[i-1][i-1];
                sum[i][j]= (sum[i][j-1] + dp[i][j])%mod;
            }
        }
        cout << (dp[len][len]+mod)%mod << endl;
    }
}
