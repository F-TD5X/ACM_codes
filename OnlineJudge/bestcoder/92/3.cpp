<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n,m;
char s[111];
int p[111],num2;
int dp[111][111][111];
vector<int> d;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("3.in","r",stdin);
    //freopen("3.out","w",stdout);
#endif
	cin >> T;
	while(T--)
	{
		d.clear();
		scanf("%d%d%s",&n,&m,s);
		m/=2;
		for(int i=0;i<n;i++)
			if(s[i]=='2')
				d.push_back(n-i);
		reverse(d.begin(),d.end());
		for(int i=0;i<d.size()+1;i++)
			for(int j=0;j<n+1;j++)
				for(int k=0;k<m+1;k++)
					dp[i][j][k]=-1;
		dp[0][0][0]=0;
		for(int i=0;i<d.size();i++)
		{
			for(int j=1;j<=n+1;j++)
				for(int k=0;k<m+1;k++)
					dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
			for(int k=0;k<m+1;k++)
				for(int k2=max(1,d[i]-m+k);k2<=min(n,d[i]+m-k)+1;k2++)
				{
					if(k2>=3 && dp[i][k2-3][k]!=-1)
						dp[i+1][k2][k+abs(d[i]-k2)]=max(dp[i+1][k2][k+abs(d[i]-k2)],dp[i][k2-3][k]+1);
					dp[i+1][k2][k+abs(d[i]-k2)]=max(dp[i+1][k2][k+abs(d[i]-k2)],dp[i][k2-1][k]);
				}
		}
		int ans=0;
		for(int i=0;i<n+1;i++)
			for(int j=0;j<m+1;j++)
				ans=max(ans,dp[d.size()][i][j]);
		cout << ans << endl;
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n,m;
char s[111];
int p[111],num2;
int dp[111][111][111];
vector<int> d;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("3.in","r",stdin);
    //freopen("3.out","w",stdout);
#endif
	cin >> T;
	while(T--)
	{
		d.clear();
		scanf("%d%d%s",&n,&m,s);
		m/=2;
		for(int i=0;i<n;i++)
			if(s[i]=='2')
				d.push_back(n-i);
		reverse(d.begin(),d.end());
		for(int i=0;i<d.size()+1;i++)
			for(int j=0;j<n+1;j++)
				for(int k=0;k<m+1;k++)
					dp[i][j][k]=-1;
		dp[0][0][0]=0;
		for(int i=0;i<d.size();i++)
		{
			for(int j=1;j<=n+1;j++)
				for(int k=0;k<m+1;k++)
					dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
			for(int k=0;k<m+1;k++)
				for(int k2=max(1,d[i]-m+k);k2<=min(n,d[i]+m-k)+1;k2++)
				{
					if(k2>=3 && dp[i][k2-3][k]!=-1)
						dp[i+1][k2][k+abs(d[i]-k2)]=max(dp[i+1][k2][k+abs(d[i]-k2)],dp[i][k2-3][k]+1);
					dp[i+1][k2][k+abs(d[i]-k2)]=max(dp[i+1][k2][k+abs(d[i]-k2)],dp[i][k2-1][k]);
				}
		}
		int ans=0;
		for(int i=0;i<n+1;i++)
			for(int j=0;j<m+1;j++)
				ans=max(ans,dp[d.size()][i][j]);
		cout << ans << endl;
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
