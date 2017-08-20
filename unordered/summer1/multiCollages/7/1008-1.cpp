#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
int hp,n,m;
int a[22];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&hp,&n,&m);
        long long **dp;
        dp = new LL*[n + 1];
        for(int i = 0; i <= n; i++)
        {
            dp[i] = new LL[1 << m];
            memset(dp[i], 0, sizeof(LL) * (1 << m));
        }
        dp[n][0]=1;
        long long sum=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d",&a[i]);
            sum+=1LL*a[i];
        }
        if(sum<hp)
        {
            printf("0/1\n");
            continue;
        }
        for(int i=n; i>=0; i--)
        {
            for(int j=0; j<(1<<m); j++)
            {
                if(dp[i][j])
                {
                    int cursum=0,curcnt=0;
                    for(int k=0; k<m; k++)
                    {
                        if(j&(1<<k)) cursum+=a[k],curcnt++;
                    }
                    int nexcnt=n-i+1-curcnt;
                    if(cursum>=hp)
                    {
                        for(int k=0; k<m; k++)
                        {
                            if(!(j&(1<<k))) dp[i][j|(1<<k)]+=dp[i][j];
                        }
                        if(i) dp[i-1][j]=dp[i][j]*i;
                    }
                    else if(nexcnt>=1)
                    {
                        for(int k=0; k<m; k++)
                        {
                            if(!(j&(1<<k))) dp[i][j|(1<<k)]+=dp[i][j];
                        }
                        if(i) dp[i-1][j]=dp[i][j]*i;
                    }
                }
            }
        }
        long long ans1=dp[0][(1<<m)-1];
        long long ans2=1;
        for(int i=1; i<=n+m; i++)
        {
            ans2=ans2*(1LL)*i;
        }
        long long ans=__gcd(ans1,ans2);
        ans1/=ans;
        ans2/=ans;
        printf("%I64d/%I64d\n",ans1,ans2);
    }
}
    
