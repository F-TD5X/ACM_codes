#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

ll n,k;

ll mpow(int n,int x){
	ll t=n,ret=1;
	while(x){
		if(x%2)
			ret=ret*t%mod;
		t=t*t%mod;
		x/=2;
	}
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
#endif
	int kase=1;
	while(cin >> n >> k)
		printf("Case #%d: %I64d\n",kase++,mpow(n,k));
	
	return 0;
}
