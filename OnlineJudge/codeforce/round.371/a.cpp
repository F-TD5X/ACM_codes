#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll l,r,l1,l2,r1,r2,k;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
#endif
    cin >> l1 >> r1>>l2>>r2>>k;
    l=max(l1,l2);
    r=min(r1,r2);
    if(l >r)
        cout << 0 << endl;
    else if(k >=l && k<=r)
        cout << r-l<<endl;
    else
        cout << r-l+1<<endl;
    return 0;
}
