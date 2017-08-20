#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
vector<int> twop[20];
vector<int> a;
int T;
int n;
int x;
ll ans;

int cmp(int x,int y)
{
	return x<y;
}

ll solve(int id,int pos)
{
	ll ret=lower_bound(twop[id].begin(),twop[id].end(),pos)-twop[id].end();
	for(auto p:twop[id])
	{
		if(p >= pos)
		{
			ll t= solve(id+1,p);
			ret=(ret+t)%mod;
		}
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> T;
	while(T--)
	{
		ans=0;
		cin >>n;
		for(int i=0;i<=16;i++)
			twop[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(log2(x)==int(log2(x)))
				twop[(int)log2(x)].push_back(i);
		}
		ll ans=solve(0,0);
		cout << -ans << endl;
	}
	return 0;
}
