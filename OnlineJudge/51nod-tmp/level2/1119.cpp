#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
ll n,m;
const ll mod=1e9+7;
ll f[2*maxn];

void init()
{
	f[0]=f[1]=1;
	for(ll i=1;i<2*maxn;i++)
		f[i]=f[i-1]*i%mod;
}

ll pow_mod(ll x,ll n)
{
	ll t=x,ret=1;
	while(n)
	{
		if(n%2)
			ret=ret*t%mod;
		t=t*t%mod;
		n>>=1;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1119.in","r",stdin);
    //freopen("1119.out","w",stdout);
#endif
	init();
	cin >> n >>m;
	ll ans=f[n-1+m-1];
	ans=ans*pow_mod(f[n-1],mod-2)%mod;
	ans=ans*pow_mod(f[m-1],mod-2)%mod;
	cout << ans << endl;
	return 0;
}
