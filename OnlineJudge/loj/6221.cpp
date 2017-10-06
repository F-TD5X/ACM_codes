/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int n;
ll a[maxn];
ll ans=0;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("6221.in","r",stdin);
    //freopen("6221.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%lld",a+i);
		sort(a+1,a+1+n);
		ans += (a[1]-a[2])*(a[1]-a[2])+(a[n]-a[n-1])*(a[n]-a[n-1]);
		for(int i=1;i<=n-2;i++)ans+=(a[i]-a[i+2])*(a[i]-a[i+2]);
		printf("%lld\n",ans);
	}

	return 0;
}
