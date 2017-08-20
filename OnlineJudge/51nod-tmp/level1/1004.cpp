#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int solve(int x,int y)
{
	ll t=x,ans=1;
	while(y)
	{
		if(y%2)
			ans=ans*t%10;
		t=t*t%10;
		y>>=1;
	}
	return ans%10;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1004.in","r",stdin);
    //freopen("1004.out","w",stdout);
#endif
	int n;
	cin>>n;
	cout << solve(n%10,n)<<endl;
	return 0;
}

