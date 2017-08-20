#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int dp[20][500][500];
int digit[20];
int len;

int dfs(int pos,int left,int right,int limit)
{
    if(pos<0)
        return left==right;
    if(!limit&&dp[pos][left][right]!=-1)
        return dp[pos][left][right];
    int end = limit?digit[pos]:9;
    int ans =0,l=0,r=0;
    for(int i=0;i<=end;i++)
    {
        l=0;
        r=0;
        for(int j=pos+1;j<len;j++)
            l+=digit[j]*fabs(pos-j);
        for(int j=pos-1;j>=0;j--)
            r+=digit[j]*(j-pos);
        ans+= dfs(pos-1,l,r,limit&&i==end);
    }
    if(!limit)
        dp[pos][left][right]=ans;
    return ans;
}

int solve(int x)
{
    len=0;
    memset(digit,0,sizeof(digit));
    while(x)
    {
        digit[len++]=x%10;
        x/=10;
    }
    int right=0;
    for(int j=len-2;j>=0;j--)
        right+=digit[j]*fabs(len-1-j);
    return dfs(len-1,0,right,1);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("f.in","r",stdin);
    //freopen("f.out","w",stdout);
#endif
    int t,n,m;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        cin >> n >> m;
        cout << solve(m)-solve(n)<<endl;
    }
    
    return 0;
}
