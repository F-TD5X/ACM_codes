#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long mo=1e9+7;
long long n;

ll cal(ll x)
{
    ll ans=1;
    ll tem=2;
    while(x)
    {
        if(x&1)
          ans=((ans%mo)*(tem%mo))%mo;
        tem=tem*tem%mo;
        x>>=1;
    }
    return ans;
}


#define H

int main()
{
#ifdef H 
    freopen("stadium.in","r",stdin);
    freopen("stadium.out","w",stdout);
#endif
    while(cin >> n)
    {
        cout<<cal(n-1)<<endl;
    }
    return 0;
}
