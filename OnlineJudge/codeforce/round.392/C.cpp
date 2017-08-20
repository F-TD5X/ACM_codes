//#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long ll;
ll cnt[111][111];
ll n,m,k,x,y,r;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n >> m >> k >> x >> y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cnt[i][j]++,r++;
	for(int i=n-1;i>=2;i--)
		for(int j=1;j<=m;j++)
			cnt[i][j]++,r++;
	ll t=(k-1)/r;
	k-=t*r;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cnt[i][j]*=t;
	for(int i=1;i<=n && k;i++)
		for(int j=1;j<=m && k;j++)
			cnt[i][j]++,k--;
	for(int i=n-1;i>=2 && k;i--)
		for(int j=1;j<=m && k;j++)
			cnt[i][j]++,k--;
	ll mi=0x3f3f3f3f3f3f3f3f,mx=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mi=min(mi,cnt[i][j]),mx=max(mx,cnt[i][j]);
	cout << mx<<" " << mi <<" " << cnt[x][y]<<endl;
	return 0;
}
