#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("L.in","r",stdin);
    //freopen("L.out","w",stdout);
#endif
	ll ll,rr;
	while(cin >> ll >> rr)
	{
		ans=0;
		for(int i=1;i<=ll;i++)
			ans+=(rr+(i%5))/5;
		cout << ans <<endl;
	}
	return 0;
}
