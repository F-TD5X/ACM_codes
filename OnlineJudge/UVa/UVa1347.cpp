#include<bits/stdc++.h>
#define FI first
#define SE second
using namespace std;
typedef long long ll;
int n;
const int maxn=1111;
pair<int,int> a[maxn];
double dp[maxn][maxn];

double dist(int x,int y)
{
	return sqrt(1.0*(a[x].FI-a[y].FI)*(a[x].FI-a[y].FI) + 1.0*(a[x].SE-a[y].SE)*(a[x].SE-a[y].SE));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa1347.in","r",stdin);
    //freopen("UVa1347.out","w",stdout);
#endif
	while(~scanf("%d",&n) && n)
	{
		for(int i=1,x,y;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			a[i].FI=x;
			a[i].SE=y;
		}
		sort(a,a+n);
		for(int i=n-1;i>=2;i--)
			for(int j=1;j<i;j++)
				if(i==n-1)
					dp[i][j]=dist(i,n)+dist(j,n);
				else
					dp[i][j]=min(dist(i,i+1)+dp[i+1][j],dist(j,i+1)+dp[i+1][i]);
		printf("%.2f\n",dist(1,2)+dp[2][1]);
	}
	return 0;
}
