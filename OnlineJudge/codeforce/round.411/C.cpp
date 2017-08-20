#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n;
	ll cnt=ceil(n/2);
	cout << cnt-1+n%2<<endl;
	return 0;
}

