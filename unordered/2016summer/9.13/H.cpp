#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int T;
ll x,y;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
    cin >>T;
    while(T--)
    {
        cin >> x>>y;
        ll ma=max(x,y);
        cout << ma*ma<<endl;
    }

    return 0;
}
