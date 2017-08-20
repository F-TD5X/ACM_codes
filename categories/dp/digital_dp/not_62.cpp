<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[50][2];
int bits[50];
int dfs(int pos,int flag,int limit)
{
	if(pos==0)
		return 1;
	if(!limit && dp[pos][flag]>=0)
		return dp[pos][flag];
	ll cnt=0;
	int last=limit?bits[pos]:9;
	for(int i=0;i<=last;i++)
		if((i==4|| (flag && i==2)))
			;
		else
			cnt+=dfs(pos-1,i==6,limit && i==last);
	return limit?cnt:dp[pos][flag];
}
int solve(int num)
{
	int len=0;
	while(num)
	{
		bits[++len]=num%10;
		num/=10;
	}
	return dfs(len,0,1);
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("not_62.in","r",stdin);
    //freopen("not_62.out","w",stdout);
#endif
	int n,m;
	memset(dp,-1,sizeof(dp));
	while(cin >> n >> m && m+n)
	{
		cout << solve(m)-solve(n-1)<<endl;
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[50][2];
int bits[50];
int dfs(int pos,int flag,int limit)
{
	if(pos==0)
		return 1;
	if(!limit && dp[pos][flag]>=0)
		return dp[pos][flag];
	ll cnt=0;
	int last=limit?bits[pos]:9;
	for(int i=0;i<=last;i++)
		if((i==4|| (flag && i==2)))
			;
		else
			cnt+=dfs(pos-1,i==6,limit && i==last);
	return limit?cnt:dp[pos][flag];
}
int solve(int num)
{
	int len=0;
	while(num)
	{
		bits[++len]=num%10;
		num/=10;
	}
	return dfs(len,0,1);
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("not_62.in","r",stdin);
    //freopen("not_62.out","w",stdout);
#endif
	int n,m;
	memset(dp,-1,sizeof(dp));
	while(cin >> n >> m && m+n)
	{
		cout << solve(m)-solve(n-1)<<endl;
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
