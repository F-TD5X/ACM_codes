#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int ans=1e9;
	cin >>a >> b>>c;
	for(int i=min(min(a,b),c);i<=max(max(a,b),c);i++)
	{
		if(fabs(i-a)+fabs(i-b)+fabs(i-c)<ans)
			ans=fabs(i-a)+fabs(i-b)+fabs(i-c);
	}
	cout << ans<<endl;
	return 0;
}
