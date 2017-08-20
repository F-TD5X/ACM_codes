#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int dp[31][11][4];
ll n,ans;
int a[30],len;
int next(int a,int b)
{
    if(a==0)
        if(b==1)
            return 1;
        else
            return 0;
    else if(a==1)
        if(b==3)
            return 2;
        else if(b==1)
            return 1;
        else
            return 0;
    return 2;
}
int dfs(int pos,int re,int v,bool b)
{
    //cout << pos << " " << re << " " << v << " " << b << " " << dp[pos][re][v] << endl;
    if(pos == -1)
        return v==2 && re==0;
    if(!b && dp[pos][re][v]!=-1)
        return dp[pos][re][v];
    int ans =0,end=b?a[pos]:9;
    for(int i=0;i<=end;i++)
        ans+=dfs(pos-1,(re*10+i)%13,next(v,i),b&&i==end);
    if(!b)
        dp[pos][re][v]=ans;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("g.in","r",stdin);
    //freopen("g.out","w",stdout);
#endif
    int n;
    int len;
    while(cin >> n)
    {
        len =0;
        for(int i=0;i<30;i++)
            for(int j=0;j<11;j++)
                for(int k=0;k<4;k++)
                    dp[i][j][k]=-1;
        while(n)
        {
            a[++len]=n%10;
            n/=10;
        }
        cout<<dfs(len-1,0,0,1)<<endl;
    }
}
