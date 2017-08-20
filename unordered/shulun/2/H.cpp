#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll expE(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	int ret=expE(b,a%b,x,y);
	int tmp=x;
	x=y;
	y=tmp-a/b*y;
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
	ll a,b,c;
	ll x,y,tx,ty;
	while(cin >> a >> b >> c)
	{
		c=-c;
		ll g=__gcd(a,b);
		if(c%g)
		{
			puts("-1");
			continue;
		}
		a/=g;
		b/=g;
		c/=g;
		expE(a,b,x,y);
		cout << x*c <<" " << y*c << endl;
	}

	return 0;
}
