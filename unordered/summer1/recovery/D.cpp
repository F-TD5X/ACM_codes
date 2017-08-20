#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,T;
double dp[5555][5555];
double p[5555],pp[5555];
int t[5555];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
    cin >> n >>T;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i] >> t[i];
        p[i]/=100.0;
    }
    for(int i=1;i<=n;i++)
    {
        pp[i] =pow(1-p[i],t[i]-1.0);
    }
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<t[j])
                dp[i][j]=(dp[i-1][j+1]+1)*p[j]+dp[i-1][j]*(1-p[j]);
            else
            {
                double tt=dp[i-1][j];
                if(i-1-t[j]>=0)
                    tt-=(dp[i-1-t[j]][j+1]+1)*pp[j];
                tt*=(1.0-p[j]);
                tt+=(dp[i-t[j]][j+1]+1)*pp[j]*(1-p[j]);
                tt+=(dp[i-1][j+1]+1)*p[j];
                dp[i][j]=tt;
            }
        }
    }
    printf("%.9f\n",dp[T][1]);
    return 0;
}
