/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(1e6+10)*2;
const ll mod=1e9+7;

ll pre[maxn],num[maxn];

ll C(){
	ll ret;
	pre[0]=1;
	for(int i=1;i<maxn;i++)
		pre[i]=pre[i-1]*i%mod;
}

ll pm(int x,int n){
	ll t=x,ret=1;
	while(n){
		if(n%2)
			ret=ret*t%mod;
		t=t*t%mod;
		n>>=1;
	}
	return ret;
}

void init(){
	C();
	num[1]=1;
	for(ll i=2;i<maxn;i++){
		num[i]=pm(pre[i],mod-2);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1119.in","r",stdin);
    //freopen("1119.out","w",stdout);
#endif
	init();
	ll n,m;
	while(~scanf("%lld%lld",&n,&m)){
		ll a=pre[n+m-2];
		ll b=num[n-1];
		ll c=num[m-1];
		printf("%lld\n",(a%mod*b%mod*c%mod)%mod);
	}

	return 0;
}
