#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_T=1000000;
const ll mod=1e9+7;

ll seri_times[max_T];

void init()
{
	ll tmp=1;
	seri_times[0]=1;
	for(ll i=1;i<max_T;i++)
	{
		tmp=(tmp*i)%mod;
		seri_times[i]=tmp;
	}
	return ;
}

ll rev_num(ll k)
{
	if(k==1)
		return 1;
	return ((-(mod/k)*rev_num(mod%k))%mod+mod)%mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F_std.in","r",stdin);
    //freopen("F_std.out","w",stdout);
#endif
	ll t,n,x,r,ret;
	init();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==1)
		{
			puts("1");
			continue;
		}
		x=sqrt(2*n);
		while(x * (x+1)>>1<n) ++x;
		r=(x*(x+1)>>1)-n;
		if(r==0)
			ret=seri_times[x+1]*rev_num(x);
		else if(r==1)
			ret=seri_times[x];
		else if(r==2)
			ret=seri_times[x+1] * rev_num(x*2);
		else 
			ret=seri_times[x]*rev_num(r-1);
		ret%=mod;
		printf("%lld\n",ret);
	}
	return 0;
}
