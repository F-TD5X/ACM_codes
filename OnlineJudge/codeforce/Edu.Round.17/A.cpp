<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> d;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	ll n,k;
	d.clear();
	cin >> n >> k;
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			d.insert(i);
			d.insert(n/i);
		}
	}
		int i=0;
		for(auto a:d)
		{
			i++;
			if(i==k)
			{
				cout <<a <<endl;
				return 0;
			}
		}
	puts("-1");
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> d;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	ll n,k;
	d.clear();
	cin >> n >> k;
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			d.insert(i);
			d.insert(n/i);
		}
	}
		int i=0;
		for(auto a:d)
		{
			i++;
			if(i==k)
			{
				cout <<a <<endl;
				return 0;
			}
		}
	puts("-1");
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
