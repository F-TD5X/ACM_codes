#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;

LL qm(LL a,LL b,LL mod)
{
    LL ret =1;
    while(b)
    {
        if(b&1)
            ret = ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    LL n,m;
    while(T--)
    {
        cin >> n >> m;
        cout << ((qm(m,n+1,MOD)-1)*qm(m-1,MOD-2,MOD))%MOD<<endl;

    }
}
