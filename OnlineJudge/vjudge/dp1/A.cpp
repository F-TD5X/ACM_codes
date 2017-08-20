#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000000
#define INF 0x7fffffff
int dp[MAXN+10];
int mmax[MAXN+10];
int a[MAXN+10];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    int n,m;
    int i,j,mmmax;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mmax[i]=0;
            dp[i]=0;
        }
        dp[0]=0;
        mmax[0]=0;
        for(i=1;i<=m;i++)
        {
             	mmmax=-INF;
                for(j=i;j<=n;j++)
                {
                    dp[j]=max(dp[j-1]+a[j],mmax[j-1]+a[j]);
                    mmax[j-1]=mmmax;
                    mmmax=max(mmmax,dp[j]);
                }
        }
        printf("%d\n",mmmax);
    }
    return 0;
}
