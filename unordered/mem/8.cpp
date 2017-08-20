#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("8.in","r",stdin);
    //freopen("8.out","w",stdout);
#endif
	int a;
	int N;
	cin >> N;
	while(N--)
	{
		cin >> a;
		ll ans=3;
		while(a--)
		{
			ans=(ans-1)*2;
		}
		cout <<ans <<endl;
	}
	return 0;
}
