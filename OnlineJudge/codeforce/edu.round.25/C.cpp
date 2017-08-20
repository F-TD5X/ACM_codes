#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
const int maxn=1e3+100;
int a[maxn];
int ans=0;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n>>k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	k*=2;
	for(int i=0;i<n;i++){
		while(a[i] > k){
			ans++;
			k*=2;
		}
		k=max(k,a[i]*2);
	}
	cout << ans << endl;

	return 0;
}
