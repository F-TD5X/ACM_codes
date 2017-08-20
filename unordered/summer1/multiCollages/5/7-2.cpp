#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
LL l,r,k;
int dig[20],len;
LL dp[21][11][11][11][11][2],ans,temp;int pre[5];
bool flag;

LL dfs(int pos,int pre[],bool inf,bool zero)
{
    int  pre2[5];
    if(!pos)
        return 1;
    LL &pp = dp[pos][pre[1]][pre[2]][pre[3]][pre[4]][zero];
    if(!inf && pp != -1)
        return pp;
    int end = inf ? dig[pos]:9;
    ans =0;
    for(int i=0;i<=end;i++)
    {
        flag = 0;
        for(int j=1;j<k && j<=len - pos && zero==0;j++)
            if(i == pre[j])
                flag =1;
        if(flag)
            continue;
        for(int j=1;j<=4;j++)
            pre2[j]=10;
        for(int j=k-1;j>=2;j--)
            pre2[j]=pre[j-1];
        if(i == 0 && zero)
            pre2[1]=10;
        else
            pre2[1] = i;
        ans += dfs(pos-1,pre2,inf && i ==end,i == 0 && zero);
        cout << ans << endl;
    }
    cout << endl;
    if(!inf)
        pp = ans;
    return ans;
}

int main()
{
    while(cin >> l>> r>>k)
    {
        memset(dp,-1,sizeof(dp));
        len=0;
        l--;
        while(l)
        {
            dig[len++] = l%10;
            l/=10;
        }
        for(int i=1;i<=4;i++)
            pre[i] =10;
        temp = dfs(len,pre,1,1);
        len  =0;
        while(r)
        {
            dig[len++] = r%10;
            r/=10;
        }
        for(int i=1;i<=4;i++)
            pre[i] = 10;
        cout << dfs(len,pre,1,1)<<endl;
    }
}
