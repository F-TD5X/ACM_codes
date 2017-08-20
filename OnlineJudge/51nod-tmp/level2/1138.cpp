#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a,k,x;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1138.in","r",stdin);
    //freopen("1138.out","w",stdout);
#endif
	cin >> x;
	int m=sqrt(x*2+0.5);
	bool flag=0;
	for(int i=m;i>=2;i--)
	{
		if((x-i*(i-1)/2)%i==0)
		{
			flag=1;
			cout << (x-i*(i-1)/2)/i << endl;
		}
	}
	if(!flag)
		puts("No Solution");
	return 0;
}
