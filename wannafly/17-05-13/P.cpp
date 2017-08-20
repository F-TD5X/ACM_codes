#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans;
const ll mod=1e9+7;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
#endif
	ll T;
	scanf("%lld",&T);
	while(T--){
		n++;
		ans=0;
		for(int i=1;i<=n;i++){
			ans=(ans+i*(n/i))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
