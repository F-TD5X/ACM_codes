#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int a,b,c,d;
	int ans=0;
	cin >> a>>b>>c>>d;
	for(int i=0;i<=a;i++)
		ans=max(ans,256*min(i,min(c,d))+32*min(a-i,b));
	cout << ans <<endl;
	return 0;
}
