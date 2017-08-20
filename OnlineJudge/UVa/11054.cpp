#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,sum,n,a;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("11054.in","r",stdin);
    //freopen("11054.out","w",stdout);
#endif
	while(cin >> n && n)
	{
		ans=sum=a=0;
		for(ll i=0;i<n;i++)
		{
			cin >> a;
			ans+=abs(sum);
			sum+=a;
		}
		cout << ans << endl;
	}
	return 0;
}
