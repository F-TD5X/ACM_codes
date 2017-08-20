//数字三角形
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn=111;
int dp[maxn][maxn];
int a[maxn][maxn];
int dep;

int solve(int i,int j)
{
	if(dp[i][j]>=0)
		return dp[i][j];
	return dp[i][j]=a[i][j]+(1==dep?0:max(solve(i+1,j),solve(i+1,j+1)));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	while(cin >> dep)
	{
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=dep;i++)
		{
			for(int j=1;j<=i;j++)
				cin >> a[i][j];
		}
		cout <<solve(1,1)<<endl;
	}
	return 0;
}
