#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(ll n)
{
	ll ret=n;
	for(ll i=2;i*i<=n;i++)
		if(n%i==0){
			ret=ret/i*(i-1);
			while(n%i==0)
				n/=i;
		}
	if(n>1) ret=ret/n*(n-1);
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	ll n;
	while(cin >> n){
		cout << phi(n)/2 << endl;
	}

	return 0;
}
