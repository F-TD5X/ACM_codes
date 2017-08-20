#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll extern_E(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    ll ret = extern_E(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return ret;
}

ll CRT(ll a[],ll mod[],int n)
{
    ll M=1;
    ll ans=0;
    for(int i=0;i<n;i++)
        M*=mod[i];
    for(int i=0;i<n;i++)
    {
        ll x,y;
        ll Mi=M/mod[i];
        extern_E(Mi,mod[i],x,y);
        ans=(ans+Mi*x*a[i])%M;
    }
    if(ans<0)
        ans+=M;
    return ans;
}

ll a[100],m[100];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1079.in","r",stdin);
    //freopen("1079.out","w",stdout);
#endif
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >>m[i] >> a[i];
    }
    cout << CRT(a,m,n)<<endl;
    return 0;
}
