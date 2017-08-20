#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6;
int n,k;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n >> k;
	int ma=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]==k)
			return 0*puts("POSSIBLE");
	}
	sort(a,a+n);
	int g=a[0];
	for(int i=1;i<n;i++)
		g=__gcd(g,a[i]);
	if(k < a[n-1] && (g==1 || k%g==0))
		return 0*puts("POSSIBLE");
	else
		return 0*puts("IMPOSSIBLE");
	return 0;
}
