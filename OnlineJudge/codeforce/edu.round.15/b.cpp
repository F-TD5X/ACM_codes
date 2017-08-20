#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n;
map<ll,int>ma;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
#endif
    int x;
    ll ans=0;
    cin >> n;
    while(n--)
    {
        scanf("%d",&x);
        for(ll a=1;a<=1LL<<40;a<<=1)
            ans += ma[a-x];
        ma[x]++;
    }
    cout << ans <<endl;
    return 0;
}
