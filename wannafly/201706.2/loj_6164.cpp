/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+100;
map<int,int> pre[maxn];
int arr[maxn];
int n,m;
int l,r,k;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("loj_6164.in","r",stdin);
    //freopen("loj_6164.out","w",stdout);
#endif
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		pre[i][arr[i]]=pre[i-1][arr[i]]+1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cout << "st: " << i << " " << "num: " << j <<" " << "count: " <<" " << pre[i][j] << endl;
	int t,ans=0;
	while(m--){
		cin >> l >> r >> k;
		ans=0;
		for(int i=1;i<=n;i++){
			if(__gcd(pre[r][i]-pre[l-1][i],k)==1)
				ans++;
			cout << i << " "  << __gcd(pre[r][i]-pre[l-1][i],k) << " " << pre[r][i] <<" " << pre[l-1][i] <<endl;
		}
		cout << ans << endl;
	}
	return 0;
}
