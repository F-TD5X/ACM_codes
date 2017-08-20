#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
int a[111],vis[111],d[111];

ll lcm(ll a,ll b)
{
	return a/__gcd(a,b)*b;
}

void dfs(int rt)
{
	vis[rt]=1;m++;
	if(!vis[a[rt]])
		dfs(a[rt]);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		d[a[i]]++;
	}
	for(int i=1;i<=n;i++)
		if(d[i]!=1)
		{
			puts("-1");
			return 0;
		}
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			m=0;dfs(i);
			if(m%2==0)
				m/=2;
			ans=lcm(ans,m);
		}
	}
	cout << ans<<endl;
	return 0;
}
