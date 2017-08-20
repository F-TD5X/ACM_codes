#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6+10;
int ans,n,a[maxn];
set<int> vis;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("11572.in","r",stdin);
    //freopen("11572.out","w",stdout);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vis.clear();
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		int l=0,r=0;
		while(r<n)
		{
			while(r<n && !vis.count(a[r])) 
				vis.insert(a[r++]);
			ans=max(ans,r-l);
			vis.erase(a[l++]);
		}
		cout << ans<<endl;
	}
	return 0;
}
