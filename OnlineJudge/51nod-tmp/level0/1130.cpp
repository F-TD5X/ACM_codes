#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
double n;
const double e=exp(1),pi=3.1415926535;
double len=0;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1130.in","r",stdin);
    //freopen("1130.out","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
    cin >> n;
    len = n*log10(n/e);
    len += log10(sqrt(2*pi*n));
    ll ans=len;
    cout << ans+1<<endl;
    }
    return 0;
}
