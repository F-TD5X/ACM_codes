<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string str[100];
ll dp[100][5];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >>n >> m;
	for(int i=0;i<n;i++)
		fill(dp[i],dp[i]+5,0x3f3f3f3f);
	for(ll i=0;i<n;i++)
	{
		cin >> str[i];
		for(ll j=0;j<m;j++)
		{
			if(isdigit(str[i][j]))
				dp[i][0]=min(dp[i][0],min(j,m-j));
			else if(isalpha(str[i][j]))
				dp[i][1]=min(dp[i][1],min(j,m-j));
			else
				dp[i][2]=min(dp[i][2],min(j,m-j));
		}
	}
	ll ans=0x3f3f3f3f;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(j!=i)
				for(int k=0;k<n;k++)
					ans=min(ans,dp[i][0]+dp[j][1]+dp[k][2]);
	cout << ans << endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string str[100];
ll dp[100][5];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >>n >> m;
	for(int i=0;i<n;i++)
		fill(dp[i],dp[i]+5,0x3f3f3f3f);
	for(ll i=0;i<n;i++)
	{
		cin >> str[i];
		for(ll j=0;j<m;j++)
		{
			if(isdigit(str[i][j]))
				dp[i][0]=min(dp[i][0],min(j,m-j));
			else if(isalpha(str[i][j]))
				dp[i][1]=min(dp[i][1],min(j,m-j));
			else
				dp[i][2]=min(dp[i][2],min(j,m-j));
		}
	}
	ll ans=0x3f3f3f3f;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(j!=i)
				for(int k=0;k<n;k++)
					ans=min(ans,dp[i][0]+dp[j][1]+dp[k][2]);
	cout << ans << endl;
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
