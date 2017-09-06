/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
const int maxn=1111;
struct Node{
	ll x,m;
	bool operator<(const Node &t)const{
		return x<t.x;
	}
}a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("J.in","r",stdin);
    //freopen("J.out","w",stdout);
#endif
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i].x >> a[i].m;
	sort(a,a+n);
	ll b=0;
	ll sum=0;
	ll ans=0;

	for(int i=0;a[i].x < 0 && i<n;i++){
		if(a[i].m > k){
			ans+=2*abs(a[i].x)*(a[i].m/k);
			a[i].m=a[i].m%k;
			i--;
		}
		else if(sum < k)
			sum+=a[i].m;
		if(sum > k){
			a[i].m=k-sum;
			ans+=2*abs(a[b].x);
			b=i;
			sum=0;
			i--;
		}
	}

	if(a[b].x < 0 && a[b].m > 0)
		ans+=2*abs(a[b].x);
	sum=0;
	b=n-1;
	for(int i=n-1;a[i].x >0 && i >=0 ;i--){
		if(a[i].m> k){
			ans+=2*a[i].x*(a[i].m/k);
			a[i].m=a[i].m%k;
			i++;
		}else if(sum < k)
			sum+=a[i].m;
		if(sum > k){
			a[i].m=sum-k;
			ans+=2*a[b].x;
			b=i;
			sum=0;
			i++;
		}
	}

	if(a[b].x >0 && a[b].m > 0)
		ans+=2*a[b].x;

	cout << ans <<endl;

	return 0;
}
