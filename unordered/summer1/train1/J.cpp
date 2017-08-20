#include<iostream>
using namespace std;
const int maxn = 1e5+10;
const int mod = 1e9+7;
typedef long long ll;
ll num;

ll pow_mod(ll a,ll b,ll m)
{
    ll ret = 1;
    a%=m;
    while(b> 0)
    {
        if(b%2==1)
            ret = (ret*a)%m;
        a = a*a%m;
        b>>=1;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    ll b=2,flag = -1;
    for(int i =0;i<n;i++)
    {
        cin >> num;
        b = pow_mod(b,num,mod);
        if(num %2 ==0) flag = 1;
    }
    b=b*pow_mod(2LL,mod-2,mod)%mod;
    ll a= (b+flag+mod)%mod*pow_mod(3LL,mod-2,mod)%mod;
    cout << a<<"/" << b<<endl;
    return 0;
}
