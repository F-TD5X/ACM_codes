#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int dig[20],len,k;
long long dp[20][11][11][11][11][2];

long long dfs(int pos,int pre[],bool inf,bool ze=1)
{
    if(!pos)return 1;
    long long *pp=&dp[pos][pre[1]][pre[2]][pre[3]][pre[4]][ze];
    if(!inf&&(*pp)!=-1)
        return *pp;
    int en=inf?dig[pos]:9;
    long long ans=0;
    for(int i=0;i<=en;i++)
    {
        int fg=0,pr[5];;
        for(int j=1;j<k&&j<=len-pos&&ze==0;j++) // 如果已经出现，则跳过本次循环
            if(i==pre[j])
                fg=1;
        if(fg)
            continue;
        for(int j=1;j<=4;j++)
            pr[j]=10;
        for(int j=k-1;j>=2;j--)//数组左移动
            pr[j]=pre[j-1];
        if(i==0&&ze)
            pr[1]=10;
        else 
            pr[1]=i;
        ans+=dfs(pos-1,pr,inf&&i==en,(i==0&&ze));
        cout << ans << endl;
    }
    cout << endl;
    if(!inf)
        *pp=ans;
    return ans;
}

int main()
{
    long long l,r;
    while(~scanf("%lld%lld%d",&l,&r,&k))
    {
        memset(dp,-1,sizeof(dp));
        l--;
        for(len=0;l;l/=10)
            dig[++len]=l%10;
        int pre[5];
        for(int i=1;i<=4;i++)
            pre[i]=10;
        long long tmp=dfs(len,pre,1);
        for(len=0;r;r/=10)
            dig[++len]=r%10;
        for(int i=1;i<=4;i++)
            pre[i]=10;
        printf("%lld\n",dfs(len,pre,1)-tmp);
    }
    return 0;
}
