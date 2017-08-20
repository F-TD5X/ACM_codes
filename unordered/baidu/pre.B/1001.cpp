/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m;
const int maxn=1111;
int dp[maxn][maxn];
const int mod=1e9+7;

int solve(int x,int y)
{
	if(x==0 || y==0)
		return 0;
	if(dp[x][y])
		return dp[x][y];
	if(y==1)
		return dp[x][y]=x;
	if(x==y)
		return dp[x][y]=1;
	int ret=0;
	for(int i=x-1;i>=y-1;i--)
		ret=(ret+solve(i,y-1))%mod;
	return dp[x][y]=ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n<m)
			swap(n,m);
		printf("%d\n",solve(n,m));
	}
	return 0;
}
