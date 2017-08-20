/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+100;
int f[maxn],invf[maxn],a[maxn];
const int mod=1e9+7;
int n;

ll qpow(const int n,int x)
{
	ll t=n;
	ll ret=1;
	while(x){
		if(x%2)
			ret=ret*t%mod;
		t=t*t%mod;
		x/=2;
	}
	return ret;
}

void init()
{
	f[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=1ll*f[i-1]*i%mod;
	invf[n]=qpow(f[n],mod-2);
	for(int i=n-1;i>=0;i--)
		invf[i]=1ll*invf[i+1]*(i+1)%mod;
	a[0]=1;a[1]=2;
	for(int i=2;i<=n;i++)
		a[i]=(1ll*2*i*a[i-1]%mod- 1ll*a[i-2]*(i-1)%mod+mod)%mod;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("loj_6160.in","r",stdin);
    //freopen("loj_6160.out","w",stdout);
#endif
	cin >> n;
	init();
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+(i&1?-1:1)*(1ll*f[n]*f[n]%mod*invf[i]%mod*invf[n-i]%mod)*invf[n-i]%mod*a[n-i]%mod*a[n-i]%mod+mod)%mod;
	cout << ans << endl;
	return 0;
}
