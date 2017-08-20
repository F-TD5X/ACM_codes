#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1066.in","r",stdin);
    //freopen("1066.out","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
    ll n,k;
    cin >> n >> k;
    if(n%(k+1))
        puts("A");
    else
        puts("B");
    }
    return 0;
}
