#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x1,x2,x3;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("10.in","r",stdin);
    //freopen("10.out","w",stdout);
#endif
	while(cin >>x1>>x2>>x3)
	{
		int t=(x1+x2+x3)/3;
		cout << abs(x1-t)+abs(x2-t)+abs(x3-t)<<endl;
	}
	return 0;
}
