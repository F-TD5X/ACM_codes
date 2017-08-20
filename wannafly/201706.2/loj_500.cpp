/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111;
int k,n,a[maxn],b[maxn],m;
int dp[maxn][maxn];
const int INF=0x3f3f3f3f;


bool check(int mid){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j]=-INF;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		double x,y;
		for(int t,j=0;j<=min(mid/b[i],m);j++){
			x=1.0*mid/a[i];
			y=1.0*b[i]/a[i]*(1.0*mid/b[i]-1.0*j);
			t=floor(y);
			for(int k=j;k<=m;k++)
				dp[i][k]=max(dp[i][k],dp[i-1][k-j]+t);
		}
	}
	if(dp[n][m]>=m)
		return 1;
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("loj_500.in","r",stdin);
    //freopen("loj_500.out","w",stdout);
#endif
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i] >> b[i];
	int l=1,r=2e8;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	cout << l << endl;

	return 0;
}
