#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=12345;
int n,m;
int dp[maxn];
int p[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("hdu-2546.in","r",stdin);
    //freopen("hdu-2546.out","w",stdout);
#endif
	while(~scanf("%d",&n) && n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		scanf("%d",&m);
		if(m<5)
			printf("%d\n",m);
		else
		{
			memset(dp,0,sizeof(dp));
			sort(p+1,p+n+1);
			int ma=p[n];
			for(int i=1;i<n;i++)
				for(int j=m-5;j>=p[i];j--)
					dp[j]=max(dp[j],dp[j-p[i]]+p[i]);
			printf("%d\n",m-ma-dp[m-5]);
		}
	}
	return 0;
}
