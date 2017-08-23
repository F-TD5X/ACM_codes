/*Author NoZuoNoDieWhyITry*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

const int N = 13;
const int M = 1<<N;
const int mod = 100000000;
int st[M],ma[M];
int dp[N][M];
bool judge1(int x)
{
    return (x&(x<<1));
}
bool judge2(int i,int x)
{
    return (ma[i]&st[x]);
}
int main()
{
    int n,m,x;
    while(~scanf("%d%d",&n,&m))
    {
        memset(st,0,sizeof(st));
        memset(ma,0,sizeof(ma));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                scanf("%d",&x);
                if(x==0)
                    ma[i]+=(1<<(j-1));
            }

        }
        int k=0;
        for(int i=0;i<(1<<m);i++){
            if(!judge1(i))
                st[k++]=i;
        }
        for(int i=0;i<k;i++)
        {
            if(!judge2(1,i))
                dp[1][i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(judge2(i,j)) 
                    continue;
                for(int f=0;f<k;f++)
                {
                    if(judge2(i-1,f))  
                        continue;
                    if(!(st[j]&st[f]))
                        dp[i][j]+=dp[i-1][f];
                }
            }
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=dp[n][i];
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
