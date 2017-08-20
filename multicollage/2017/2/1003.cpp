/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=5e5+1000;
int a[maxn],b[maxn];
int mx[maxn];
const int mod=1e9+7;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		mx[n]=-1;
		for(int i=n-1;i>=0;i--)
			mx[i]=max({mx[i+1],a[i]-i-1});
		for(int i=0;i<n;i++)
			scanf("%d",b+i);
		sort(b,b+n);
		ll ans=0;
		a[n]=0;
		for(int i=0;i<n;i++){
			a[i+n]=max(mx[b[i]-1],a[n]);
			ans=(ans+a[i+n])%mod;
			a[i+n]-=i+n+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
