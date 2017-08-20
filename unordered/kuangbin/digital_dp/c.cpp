#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll dp[10][10];
int a[50],len;
ll get(ll n)
{
    ll ans =0;
    len =0;
    memset(a,0,sizeof(a));
    while(n)
    {
        a[++len]=n%10;
        n/=10;
    }
    for(int i=len;i;i--)
    {
        for(int j=0;j<a[i];j++)
        {
            if(j!= 4 && !(a[i+1]==6&&j==2))
                ans+=dp[i][j];
        }
        if(a[i] ==4 || (a[i]==2 && a[i+1]==6))
            break;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
#endif
    dp[0][0]=1;
    for(int i=1;i<10;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9;k++)
                if(j != 4 &&! (k == 2 &&  j==6))
                    dp[i][j] += dp[i-1][k];
    int n,m;
    while(cin >> n >> m && n+m)
    {
        cout << get(m+1)-get(n)<<endl;
    }
    return 0;
}
