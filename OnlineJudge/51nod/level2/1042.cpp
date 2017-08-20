/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
ll dp1[30],dp2[30];

void DP(ll a,ll b,ll c[])
{
	ll n=a/10,m=a%10,t=n;
	for(int i=0;i<=m;i++)
		c[i]+=b;
	for(int i=0;i<10;i++)
		c[i]+=b*n;
	c[0]-=b;
	while(t){
		c[t%10]+=b*(m+1);
		t/=10;
	}
	if(n)
		DP(n-1,b*10,c);
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1042.in","r",stdin);
    //freopen("1042.out","w",stdout);
#endif
	while(cin >> a >>b){
		DP(a-1,1,dp1);
		DP(b,1,dp2);
		for(int i=0;i<10;i++)
			cout << dp2[i]-dp1[i]<<endl;
	}

	return 0;
}
