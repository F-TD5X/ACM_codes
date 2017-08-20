#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+19;
int a[maxn],b[maxn],c[maxn],d[maxn],num[60];
int n;
ll all;

ll mk1(ll x)
{
	ll ret=0;
	for(int i=0;i<60;i++)
		if(x&(1ll<<i))
			ret+=num[i]*(1ll<<i);
	return ret;
}

ll mk2(ll x)
{
	ll ret=0;
	for(int i=0;i<60;i++)
		if(x&(1ll<<i))
			ret+=n*(1ll<<i);
		else
			ret+=num[i]*(1ll<<i);
	return ret;
}

int ok()
{
	for(int i=1;i<=n;i++)
	{
		a[i]=(d[i]-all)/n;
		if(a[i]<0)
			return 0;
		int now=0,t=a[i];
		while(t)
		{
			if(t&1)num[now]++;
			now++;
			t/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mk1(a[i])!=b[i])
			return 0;
		if(mk2(a[i])!=c[i])
			return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> b[i];
		d[i]+=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		d[i]+=c[i];
		all+=d[i];
	}
	all/=2*n;
	if(ok())
	{
		for(int i=1;i<=n;i++)
			cout <<a[i]<<" ";
		cout<<endl;
		return 0;
	}
	puts("-1");
	return 0;
}
