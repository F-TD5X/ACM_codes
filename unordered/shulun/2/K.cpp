#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("K.in","r",stdin);
    //freopen("K.out","w",stdout);
#endif
	ll n,a,b,q,p,ans;
	while(cin >> n >> a >> b>>p>>q)
	{
		ans=p*(n/a)+q*(n/b)-min(p,q)*(n/(a*b));
		cout <<ans<<endl;
	}
	return 0;
}
