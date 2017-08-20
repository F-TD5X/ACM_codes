#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isp(ll n)
{
	if(n<=1)
		return 0;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	ll n;
	while(cin >> n)
	{
		if(isp(n))
			cout << 1<<endl;
		else if(n%2)
			cout <<3<<endl;
		else
			cout <<2<<endl;
	}
	return 0;
}
