/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int times=20;
const ll mod=998244353;
const ll maxn=1e6+100;
int T;
int cnt_p;
map<ll,ll> mp;
ll l,r,k;


inline ll Random(ll n)
{
	return (double)rand()/RAND_MAX*n+0.5;
}

inline ll qmul(ll a, ll b,ll mod){
	ll ret=0;
	while(b){
		if(b&1)
			ret=(ret+a)%mod;
		b>>=1;
		a=(a+a)%mod;
	}
	return ret;
}

inline ll qpow(ll a,ll b,ll mod){
	ll ret=1;
	while(b){
		if(b&1)
			ret=qmul(ret,a,mod);
		b>>=1;
		a=qmul(a,a,mod);
	}
	return ret;
}

inline bool witness(ll a,ll n){
	ll tem=n-1;
	int j=0;
	while(tem%2==0){
		tem>>=1;
		j++;
	}
	ll x=qpow(a,tem,n);
	if(x==1 || x==n-1)
		return 1;
	while(j--){
		x=qmul(x,x,n);
		if(x==n-1)
			return 1;
	}
	return 0;
}

inline bool miller(ll n){
	if(n==2)
		return 1;
	if(n<2 || n%2==0)
		return 0;
	for(int i=1;i<=times;i++){
		ll a=Random(n-2)+1;
		if(!witness(a,n))
			return false;
	}
	return 1;
}

inline ll pollard_rho(ll n,ll c){
	ll x,y,d,i=1,k=2;
	x=Random(n-1)+1;
	y=x;
	while(1){
		i++;
		x=(qmul(x,x,n)+c)%n;
		d=__gcd(y-x,n);
		if(1 < d  && d<n)
			return d;
		if(y==x)
			return n;
		if(i==k){
			y=x;
			k<<=i;
		}
	}
}

void find(ll n,ll c){
	if(n==1)
		return;
	if(miller(n)){
		mp[n]++;
		return;
	}
	ll p=n;
	while(p>=n)
		p=pollard_rho(p,c--);
	find(p,c);
	find(n/p,c);
}

inline ll cac(ll n){
	mp.clear();
	find(n,2137342);
	int ret=1;
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++){
		ret=(ret*(it->second*k+1))%mod;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1003.in","r",stdin);
    freopen("1003.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		ll ans=0;
		scanf("%lld%lld%lld",&l,&r,&k);
		for(ll i=l;i<=r;i++)
			ans=(ans+cac(i))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
