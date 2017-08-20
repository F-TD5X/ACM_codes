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
const int maxn = 1e5+10;
ll a[maxn],b[maxn];
ll ans=0;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
#endif
    int n,m,ini;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=1;i<=m;i++)
        cin >> b[i];
    b[0]=-1e17;
    b[m+1]=1e17;
    m+=2;
    for(int i=0;i<n;i++)
    {
        ini = lower_bound(b,b+m,a[i])-b;
        ans = max(ans,(ll)min(fabs(a[i]-b[ini]),fabs(a[i]-b[ini-1])));
    }
    cout << ans <<endl;
    return 0;
}
