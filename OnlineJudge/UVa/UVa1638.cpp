#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=30;
int n;
ll dp[maxn][maxn][maxn];
int l,r;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa1638.in","r",stdin);
    //freopen("UVa1638.out","w",stdout);
#endif
	dp[1][1][1]=1;
	for(int i=2;i<=20;i++)
		for(int j=1;j<=i;j++)
			for(int k=1;k<=i;k++)
			{
				dp[i][j][k]=dp[i-1][j][k]*(i-2);
				if(j>1)
					dp[i][j][k]+=dp[i-1][j-1][k];
				if(k>1)
					dp[i][j][k]+=dp[i-1][j][k-1];
			}
	int T;
	cin >> T;
	while(T--)
	{
		cin >>n >> l >> r;
		cout << dp[n][l][r]<<endl;
	}
	return 0;
}
