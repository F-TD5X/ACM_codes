#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int gcd(int a,int b)
{
    if(b == 0) return a;
    else
        return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1002.in","r",stdin);
    //freopen("1002.out","w",stdout);
#endif
    ll m,n;
    ll ans1,ans2,ans;
    while(cin >> n >> m && n+m)
    {
        ans1 = n*(m-1);
        ans2= m*m;
            ans = gcd(ans1,ans2);
            ans1 /=ans;
            ans2 /=ans;
            cout << ans1 <<"/"<<ans2<<endl;
    }
    return 0;
}
