#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e3+10;
char str[maxn];
int p[maxn][maxn],vis[maxn][maxn];
int kase;
int dp[maxn];

int charge(int i,int j)
{
	if(i>=j)
		return 1;
	if(str[i]!=str[j])
		return 0;
	if(vis[i][j]==kase)
		return p[i][j];
	vis[i][j]=kase;
	p[i][j]=charge(i+1,j-1);
	return p[i][j];
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("11584.in","r",stdin);
    //freopen("11584.out","w",stdout)
#endif
	int t;
	cin >> t;
	for(kase=1;kase<=t;kase++)
	{
		scanf("%s",str+1);
		int len=strlen(str+1);
		dp[0]=0;
		for(int i=1;i<=len;i++)
		{
			dp[i]=i+1;
			for(int j=0;j<i;j++)
				if(charge(j+1,i))
					dp[i]=min(dp[i],dp[j]+1);
		}
		cout <<dp[len]<<endl;
	}
	return 0;
}
