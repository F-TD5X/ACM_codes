#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int a,b,c;
	cin >> a >>b>>c;
	a/=1;
	b/=2;
	c/=4;

	cout << min(a,min(b,c))*7<<endl;
	return 0;
}
