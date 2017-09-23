/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,k;
const int maxn=1e5+10,INF=0x3f3f3f3f;
int a[maxn];
int dp[maxn];
int d[maxn];

int LIS(){
	int ret=-1;
	memset(dp,INF,sizeof(dp));
	for(int i=0;i<n;i++){
		int j=lower_bound(dp,dp+n,a[i])-dp;
		d[i]=j+1;
		if(ret<d[i])
			ret=d[i];
		dp[j]=a[i];
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1004.in","r",stdin);
    //freopen("1004.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		int t1=LIS();
		reverse(a,a+n);
		int t2=LIS();
		if(n-t1==k || n-t2==k)
			puts("A is a magic array.");
		else
			puts("A is not a magic array.");
	}

	return 0;
}
