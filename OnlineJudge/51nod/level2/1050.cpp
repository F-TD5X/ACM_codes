/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=50010;
ll a[maxn];
ll s;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1050.in","r",stdin);
    //freopen("1050.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		s+=a[i];
	}
	ll sum=0;
	ll ans1=0,ans2=0;
	for(int i=0;i<n;i++){
		if(sum<0)
			sum=a[i];
		else
			sum+=a[i];
		ans1=max(ans1,sum);
	}
	for(int i=0;i<n;i++)
		a[i]=-a[i];
	sum=0;
	for(int i=0;i<n;i++ ){
		if(sum<0)
			sum=a[i];
		else
			sum+=a[i];
		ans2=max(ans2,sum);
	}
	cout <<max(ans1,s+ans2) << endl;


	return 0;
}
