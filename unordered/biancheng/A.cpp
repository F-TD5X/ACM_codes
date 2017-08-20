#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int t;
	cin >> t;
	int n,m;
	while(t--)
	{
		cin >> m>>n;
		ll ans=m;
		while(n--)
		{
			ans=ans*2+1;
		}
		cout << ans << endl;
	}
	return 0;
}
