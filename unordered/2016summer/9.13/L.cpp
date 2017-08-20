#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int prime[100];
int ans;
int l,r;
int dp[int(1e5+10)];
int c;
int cnt(int x)
{
    int ret=0;
    while(x)
    {
        if(x%2)
            ret++;
        x/=2;
    }
    return ret;
}

bool isp(int x)
{
    if(x==1||x==2)
        return 1;
    for(int i=2;i<x;i++)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("L.in","r",stdin);
    //freopen("L.out","w",stdout);
#endif
    prime[2]=prime[3]=1;
    for(int i=2;i<=20;i++)
    {
        if(isp(i))
            prime[i]=1;
    }
    for(int i=1;i<=1e5+10;i++)
    {
        if(prime[cnt(i)])
            c++;
        dp[i]=c;
    }
    int T;
    cin >>T;
    while(T--)
    {
        ans=0;
        cin >> l >>r;
        cout << dp[r]-dp[l-1]<<endl;
    }
    return 0;
}
