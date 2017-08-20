#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=(2e5+10)*2;
ll ans;
ll n,x,a[maxn],f[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	while(cin >> n)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		ans=0;
		while(n--)
		{
			cin >>x;
			a[x]++;
		}
		for(ll i=200000;i;i--)
			f[i]=f[i+1]+a[i];
		for(ll i=1;i<=200000;i++)
		{
			if(a[i])
			{
				ll sum=0;
				for(ll j=i;j<=200000;j+=i)
					sum+=(ll)(f[j]-f[j+i])*j;
				ans=max(sum,ans);
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}
