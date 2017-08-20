#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[222222];
int n,x,y;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	ll ans=0;
	cin >> n >> x;
	for(int i=1;i<=n;i++)
	{
		cin >> y;
		ans+=num[x^y];
		++num[y];
	}
	cout << ans<<endl;
	return 0;
}
