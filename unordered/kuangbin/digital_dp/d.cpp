#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll dp[55][3];
ll T,ans;
unsigned long long n;
bool flag;
int a[55];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
#endif
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<55;i++)
    {
        dp[i][0] = dp[i-1][0]*10-dp[i-1][1];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][2]*10+dp[i-1][1];
    }
    cin >> T;
    int len;
    while(T--)
    {
        flag= 0;
        len = 0;
        ans =0;
        cin >> n;
        while(n)
        {
            a[len++]=n%10;
            n/=10;
        }
        for(int i=len-1;i>=0;i--)
        {
            ans += dp[i][2]*a[i];
            if(flag)
                ans += dp[i][0]*a[i];
            if(!flag && a[i] >4)
                ans += dp[i][1];
            if(a[i]==9 && a[i+1] == 4)
                flag = 1;
            if(a[i]==9 && a[i+1]==4 && i==0)
                ans++,flag=1;
        }
        cout << ans <<endl;
    }
    return 0;
}
