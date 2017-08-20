#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef __int64 LL;
LL dp[27][3];
int c[27];
void init()  
{  
    memset(dp,0,sizeof(dp));  
    dp[0][0] = 1;  
    for(int i = 1; i <= 20; i++)  
    {  
        dp[i][0] = dp[i-1][0]*10-dp[i-1][1];  
        dp[i][1] = dp[i-1][0]*1;  
        dp[i][2] = dp[i-1][2]*10+dp[i-1][1];  
    }  
}  
  
int cal(LL n)  
{  
    int k = 0;  
    memset(c,0,sizeof(c));  
    while(n)  
    {  
        c[++k] = n%10;  
        n/=10;  
    }  
    c[k+1] = 0;  
    return k;  
}  
void solve(int len, LL n)  
{  
    int flag = 0; 
    LL ans = 0;  
    for(int i = len; i >= 1; i--)  
    {  
        ans+=c[i]*dp[i-1][2];  
        if(flag)  
        {  
            ans+=c[i]*dp[i-1][0];  
        }  
        else if(c[i] > 4)  
        {  
            ans+=dp[i-1][1];  
        }  
        if(c[i+1]==4 && c[i]==9)  
        {  
            flag = 1;  
        }  
    }  
    printf("%I64d\n",ans);  
}  
int main()  
{  
    int t;  
    LL n;  
    init();  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%I64d",&n);  
        int len = cal(n+1);  
        solve(len, n);  
    }  
    return 0;  
}  
