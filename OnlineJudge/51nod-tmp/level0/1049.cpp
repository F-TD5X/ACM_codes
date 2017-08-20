#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll a[55555],dp[55555],n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1049.in","r",stdin);
    //freopen("1049.out","w",stdout);
#endif
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i-1]>0)
            dp[i]=dp[i-1]+a[i];
        else 
            dp[i]=a[i];
        if(dp[i]>ans)
            ans=dp[i];
    }
    cout << ans << endl;
    return 0;
}
