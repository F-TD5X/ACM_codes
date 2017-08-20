#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int size[1<<10],nex_t[1<<10][10];
int dp[20][1<<10][11];
int digit[20],K;
ll dfs(int len,int state,bool zero,bool flag)
{
    if(len ==0)
        return size[state]==K;
    if(!flag && dp[len][state][K]!=-1)
        return dp[len][state][K];
    ll ans=0;
    int end= flag?digit[len]:9;
    for(int i=0;i<=end;i++)
        ans += dfs(len-1,(zero && i==0)?0:nex_t[state][i],zero && i==0,flag&& i==end);
    return !flag?dp[len][state][K]=ans:ans;
}

ll solve(ll x)
{
    int len = 0;
    while(x)
    {
        digit[++len]=x%10;
        x/=10;
    }
    return dfs(len,0,1,1);
}

int fnext(int status,int num)
{
    for(int i=num;i<10;i++)
        if(status&(1<<i))
            return (status^(1<<i))|(1<<num);
    return status|(1<<num);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
#endif
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<1<<10;i++)
    {
        size[i]=0;
        for(int j=0;j<10;j++)
        {
            if(i&(1<<j))
                size[i]++;
            nex_t[i][j]=fnext(i,j);
        }
    }
    int T;
    cin >> T;
    for(int cas=1;cas<=T;cas++)
    {
        ll l,r;
        cin >> l>>r>>K;
        cout << "Case #"<<cas<<": "<<solve(r)-solve(l-1) << endl;
    }
    return 0;
}
