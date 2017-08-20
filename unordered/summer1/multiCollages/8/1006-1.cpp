#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int v[100010],t,k,n,m,C,T;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1006-1.in","r",stdin);
    //freopen("1006-1.out","w",stdout);
#endif
    cin >>T;
    while(T--)
    {
        cin >> n >>C;
        for(int i=1 ;i<=n;i++)
            cin >> v[i] >> t >> t;
        cin >>m;
        sort(v+1,v+1+n);
        while(m--)
        {
            cin >> t >> k;
            printf("%.3f\n",sqrt(1LL*2*C*t +1LL*v[k]*v[k]));
        }
    }
    return 0;
}
