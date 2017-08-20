#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int s,ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1283.in","r",stdin);
    //freopen("1283.out","w",stdout);
#endif
    cin >> s;
    ans=1e9;
    for(int i=sqrt(s);i>=1;i--)
    {
        if(s%i==0)
            ans=min(ans,2*(i+s/i));
    }
    cout << ans <<endl;
    return 0;
}
