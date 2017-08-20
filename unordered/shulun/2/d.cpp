#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	while(cin >>n  >>m)
		cout << min(n,min(m,(n+m)/3))<<endl;
	return 0;
}
