#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("7.in","r",stdin);
    //freopen("7.out","w",stdout);
#endif
	double k,n,w;
	while(cin >> k >> n >> w)
	{
		ll all=0;
		for(int i=1;i<=w;i++)
			all+=k*i;
		cout << (all-n>0?all-n:0)<<endl;
	}
	return 0;
}
