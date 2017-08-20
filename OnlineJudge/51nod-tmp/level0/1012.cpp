#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1012.in","r",stdin);
    //freopen("1012.out","w",stdout);
#endif
    ll a,b;
    cin >> a>>b;
    cout << lcm(a,b)<<endl;
    return 0;
}
