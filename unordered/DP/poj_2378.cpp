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
const int maxn=10002;
int dp[maxn],sum[maxn],n,flag;
vector<int>p[maxn];
int dfs(int u,int fa)
{
    int  i,j,v,sum=1,mson=0;
    int cnt=p[u].size();
    dp[u]=0;//子孩子
    for(i=0;i<cnt;i++)
    {
        v=p[u][i];
        if(v==fa)continue;
        int ans=dfs(v,u);
        mson=max(mson,ans);
        sum+=ans;
    }
    dp[u]=max(n-sum,mson);
    return sum;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("poj_2378.in","r",stdin);
    //freopen("poj_2378.out","w",stdout);
#endif

    while(~scanf("%d",&n)){
        int a,b;
        flag=0;
        for(int i=1;i<=n;i++)
			p[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            p[a].push_back(b);
            p[b].push_back(a);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++){
            if(2*dp[i]<=n){
                flag=1;
                printf("%d\n",i);
            }
        }
        if(!flag)printf("NONE\n");
    }
    return 0;
}
