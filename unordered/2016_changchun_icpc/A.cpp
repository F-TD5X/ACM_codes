#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int p;
int n[13],c[13],w[13];
map<int,int> dp[13];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >>T;
	c[0]=1;c[1]=5;c[2]=10;c[3]=20;c[4]=50;c[5]=100;c[6]=200;c[7]=500;c[8]=1000;c[9]=2000;
	while(T--)
	{
		cin >> p;
		for(int i=0;i<10;i++)
			dp[i].clear();
		for(int i=0;i<10;i++)
			cin >> n[i];
		for(int i=0;i<10;i++)
		{
			for(int k=0;k<=n[i];k++)
				dp[i][p]=max(dp[i-1][p-k*c[i]] +  k,dp[i][p]);
		}
		if(dp[9][p]=0)
			cout << -1 <<endl;
		else
			cout << dp[9][p]<<endl;
	}
	return 0;
}
