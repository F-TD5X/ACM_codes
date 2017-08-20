#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+10;
ll aim,n,m;
ll x,s;
ll b[maxn],c[maxn];
struct SK
{
	ll c,e;
}a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> aim>>n>>m;
	cin >> x>>s;
	for(int i=0;i<n;i++)
		cin >> a[i].e;
	for(int i=0;i<n;i++)
		cin >> a[i].c;
	for(int i=0;i<m;i++)
		cin >> b[i];
	for(int i=0;i<m;i++)
		cin >> c[i];
	ll ans=min(aim*x,(aim-b[upper_bound(c,c+m,s)-c-1])*x);
	for(int i=0;i<n;i++)
	{
		if(s-a[i].c<0)
			continue;
		int ind=upper_bound(c,c+m,s-a[i].c)-c-1;
		ans=min(ans,(aim-b[ind])*a[i].e);	
	}
	cout << ans <<endl;
	return 0;
}
