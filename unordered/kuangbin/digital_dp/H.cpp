#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int digit[20],dp[20][200000],sum;

int dfs(int len,int pre,bool limit)
{
    if(len <0)
        return pre>=0;
    if(pre<0)
        return 0;
    if(!limit && dp[len][pre] != -1)
        return dp[len][pre];
    int end = limit?digit[len]:9;
    int ret=0;
    for(int i=0;i<=end;i++)
        ret+=dfs(len-1,pre-i*(1<<len),limit&&i==end);
    return limit?ret:dp[len][pre]=ret;
}

int solve(int x)
{
    int len = 0;
    while(x)
    {
        digit[len++]=x%10;
        x/=10;
    }
    return dfs(len-1,sum,1);
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
    int t,n,m;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    for(int cas=1;cas<=t;cas++)
    {
        sum=0;
        int i=0;
        memset(digit,0,sizeof(digit));
        cin >> n >> m;
        while(n)
        {
            sum += n%10*(1<<i);
            i++;
            n/=10;
        }
        cout << "Case #"<<cas<<": "<<solve(m)<<endl;
    }

    return 0;
}
