#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e6+10;
ll a,b,c;
int ans;
int n;
ll x,y,xx,yy;
ll t1,t2;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
    cin >>x>>y>>xx>>yy;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a>>b>>c;
        t1 = a*x+b*y+c;
        t2 = a*xx+b*yy+c;
        if((t1<=0 && t2 >=0)||(t1>=0 && t2<=0))
            ans++;
    }
    cout << ans<<endl;
    return 0;
}
