#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e5+10;
const ll INF =  1000000000000000LL;
ll dp[maxn][2];
int n,c[maxn];
string s[maxn],rs1,rs2;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
#endif
    cin >>n;
    for(int i=0;i<n;i++)
        dp[i][0] = dp[i][1] = INF;
    for(int i=0;i<n;i++)
        cin >>c[i];
    for(int i=0;i<n;i++)
        cin >>s[i];
    dp[0][0]=0;
    dp[0][1]=c[0];
    for(int i=1;i<n;i++)
    {
        rs1 = s[i-1];
        rs2=s[i];
        reverse(rs1.begin(),rs1.end());
        reverse(rs2.begin(),rs2.end());
        if(s[i-1] <= s[i])
            dp[i][0] = min(dp[i][0],dp[i-1][0]);
        if(rs1 <= s[i]) 
            dp[i][0] = min(dp[i][0],dp[i-1][1]);
        if(rs2 >= s[i-1])
            dp[i][1] = min(dp[i][1],dp[i-1][0] + c[i]);
        if(rs2 >= rs1)
            dp[i][1] = min(dp[i][1],dp[i-1][1]+ c[i]);
    }
    if(dp[n-1][0] < INF || dp[n-1][1]<INF)
        cout << min(dp[n-1][1],dp[n-1][0])<<endl;
    else
        cout << -1 <<endl;
    return 0;
}
