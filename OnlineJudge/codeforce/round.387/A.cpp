#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif

	int n;
	cin >> n;
	int a,b;
	for(int i=1;i<=n;i++)
	{
		if(n%i)
			continue;
		if(n/i>=i)
		{
			a=i;b=n/i;
		}
	}
	cout << a <<" " << b << endl;
	return 0;
}
