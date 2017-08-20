#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n;
const int mod =10007; 
ll a[110000];
ll ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        ans+=a[i]*a[n-1-i];
        ans%=mod;
    }
    cout << ans <<endl;
    return 0;
}
