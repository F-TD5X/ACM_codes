#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111;
int b,n,s[maxn],c[maxn];
int kase=1;
int dp[1111][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	while(~scanf("%d%d",&b,&n)){
		for(int i=1;i<=n;i++)
			scanf("%d%d",s+i,c+i);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=b;j++){
				if(c[i]>j)continue;
				if(dp[i-1][j-c[i]] + s[i] > dp[i-1][j]){
					dp[i][j]=dp[i-1][j-c[i]]+s[i];
				}
			}
		}
	}

	return 0;
}
