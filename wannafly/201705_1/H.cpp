#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M,K,W,T;
const int maxn=11111;
int dp[2][500][500],mp[500][500],s[500][500];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
	while(~scanf("%d%d%d",&N,&M,&K) && N+M+K){
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++){
				cin >> s[i][j];
				s[i][j]+=s[i][j-1];
			}
		memset(dp,-1,sizeof(dp));
		scanf("%d",&T);
		memset(mp,0,sizeof(mp));
		int x,y;
		while(T--){
			cin >> x>>y;
			mp[x][y]=1;
		}
		dp[0][0][0]=0;
		int ans=0;
		for(int i=1;i<=N;i++){
			dp[0][i][0]=dp[0][i-1][0];
			for(int j=1;j<=i*M && j<=K;j++){
				dp[0][i][j]=dp[0][i-1][j];
				dp[1][i][j]=max(dp[0][i][j],dp[1][i][j]);
				for(int k=1,p=1;j<=j && p<=M;k++)
					for(;p<=M;p++)
						if(mp[i][p]){
							if(dp[0][i-1][j-k]>=0)
								dp[1][i][j]=max(dp[1][i][j],dp[0][i-1][j-k]+s[i][p]);
							if(dp[1][i-1][j-k+1]>=0)
								dp[1][i][j]=max(dp[1][i][j],dp[1][i-1][j-k+1]+s[i][p]);
							if(dp[0][i-1][j-k+1]>=0)
								dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-k+1] +s[i][p]);
						}else{
							if(dp[0][i-1][j-k]>=0)
								dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-k]+s[i][p]);
							if(dp[1][i-1][j-k+1]>=0)
								dp[0][i][j]=max(dp[0][i][j],dp[1][i-1][j-k+1]+s[i][p]);
						}
			}
			if(i==N)
				ans=max(ans,max(dp[0][i][K],dp[1][i][K]));
		}
		cout << ans << endl;
	}
	return 0;
}
