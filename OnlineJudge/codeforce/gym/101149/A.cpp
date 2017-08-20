#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int n,ans=0;
	cin >>n;
	for(int x,i=0;i<n;i++)
	{
		cin >> x;
		ans=max(ans,x);
	}
	cout << ans<<endl;
	return 0;
}
