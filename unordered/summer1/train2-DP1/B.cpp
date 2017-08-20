#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,ans;
int dp[111];

int main()
{
    cin >>T;
    memset(dp,0,sizeof(dp));
    dp[1]=1;dp[2]=2;
    while(T--)
    {
        cin >>n;
        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        cout << dp[n-1]<<endl;
    }
}
