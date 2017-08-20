#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int now=1,n,m,ans,l,r;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    cin >> n  >> m;
    for(int i=0;i<n;i++)
    {
        cin >> l >>r;
        if((l-now)/m>=1)
        {
            ans += (l-now)%m;
        }
        else
            ans+=(l-now);
        ans+=r-l+1;
        now = r+1;
    }
    cout << ans << endl;
    return 0;
}
