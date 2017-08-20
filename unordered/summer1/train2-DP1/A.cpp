#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=111;

int mp[111][111],dp[111][111],n;

int solve(int i,int j)
{
    if(dp[i][j] >=0) return dp[i][j];
    else
        return dp[i][j] = mp[i][j]+(i==n+1?0:max(solve(i+1,j),solve(i+1,j+1)));
}

int main()
{
    int T;
    cin >>T;
    while(T--){
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cin >> mp[i][j];
    }
    solve(1,1);
    cout << dp[1][1] << endl;
}
}
