#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	ll n;
	while(cin >> n)
	{
		//ll t=clock();
		int ans=1;
		if(n==1)
			puts("0");
		else if(n==2)
			puts("1");
		else if(n==3)
			puts("2");
		else
		{
			ll a=2,b=3;
			ll tmp;
			while(1)
			{
				ans++;
				tmp=a+b;
				if(tmp>n)
					break;
				a=b;
				b=tmp;
			}
			cout <<ans<<endl;
		}
	}
	return 0;
}
