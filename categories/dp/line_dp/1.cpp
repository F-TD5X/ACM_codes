//导弹拦截
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int maxn=1e4+20;
int dp[maxn];
int a[maxn];
int tmp[maxn];
int cnt,kase;

int solve()
{
	memset(dp,0,sizeof(dp));
	memset(tmp,0,sizeof(tmp));
	int ret=1;
	reverse(a+1,a+cnt+1);
	tmp[1]=a[1];
	for(int i=2;i<=cnt;i++)
	{
		if(a[i]>=tmp[ret])
			tmp[++ret]=a[i];
		else
			tmp[lower_bound(tmp,tmp+ret,a[i])-tmp]=a[i];
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
#endif
	int d;
To:
	cnt=0;
	kase++;
	while(cin >> d && d!=-1)
		a[++cnt]=d;
	if(cnt)
	{
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",kase,solve());
		goto To;
	}
	return 0;
}
