#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll PM(int n)
{
	ll ret=1,t=1378;
	while(n)
	{
		if(n%2)
			ret=ret*t%10;
		t=t*t%10;
		n=n/2;;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int n;
	cin >>n;
	cout << PM(n)<<endl;
	return 0;
}
