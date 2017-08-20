#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans;
int n;
int a[111];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	int mx=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	for(int i=0;i<n;i++)
	{
		ans+=mx-a[i];
	}
	cout << ans <<endl;
	return 0;
}
