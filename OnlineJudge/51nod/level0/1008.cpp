#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
#endif
	ll n,p;
	while(~scanf("%lld%lld",&n,&p))
	{
		ll ans=1;
		for(ll i=1;i<=n;i++)
			ans=ans*i%p;
		cout <<ans<<endl;
	}
	return 0;
}
