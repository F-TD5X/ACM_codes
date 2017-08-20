#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=1e5+10;
int a[maxn];
int p[maxn];
bool ok[maxn];
int fa[maxn];
ll s[maxn];
ll ans[maxn];

int fi(int u)
{
	if(fa[u]!=u)
		fa[u]==fi(fa[u]);
	return fa[u];
}

int uni(int u,int v)
{
	u=fi(u),v=fi(v);
	fa[u]=v;
	s[v]+=s[u];
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C-1.in","r",stdin);
    //freopen("C-1.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
	{
		cin >> p[i];
		p[i]--;
		fa[i]=i;
	}
	ll rans=0;
	for(int i=n-1;i>=0;i--)
	{
		s[p[i]]=a[p[i]];
		if(p[i]>0 && ok[p[i]-1])
			uni(p[i],p[i]-1);
		if(p[i]+1<n && ok[p[i]+1])
			uni(p[i],p[i]+1);
		ok[p[i]]=1;
		ans[i]=rans;
		rans=max(rans,s[fi(p[i])]);
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << endl;
	return 0;
}
