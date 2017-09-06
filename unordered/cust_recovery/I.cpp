/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ma;
ll ans,sum;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
#endif
	cin >>n;
	ll x;
	for(int i=0;i<n;i++){
		cin >> x;
		sum+=x;
		ma=max(ma,x);
	}
	sum-=ma;
	if(sum >=ma)
		cout << (sum+ma)/2 << endl;
	else
		cout << sum << endl;
	return 0;
}
