#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,m,k;
	cin >> n >> m >> k;
	if(n==m)
	{
		cout << 1 << endl;
		return 0;
	}
	m-=n+1;
	int ans=2;
	int l=max(k-1,1),r=min(k+1,n);
	while((l>1 || r<n)&& m>=(r-l+1))
	{
		m-=r-l+1;
		ans++;
		if(l>1)
			l--;
		if(r<n)
			r++;
	}
	int len=r-l+1;
	ans+=m/len;
	cout << ans << endl;
	return 0;
}
