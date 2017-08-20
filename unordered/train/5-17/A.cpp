#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
const int maxn=1005,INF=0x3f3f3f3f;
int dp[maxn][10][10];
char s1[maxn],s2[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	while(cin >> s1 >> s2)
	{
		int len=strlen(s1);
		memset(dp,INF,sizeof(dp));
		dp[0][0][0]=0;
		for(int i=0;i<len;i++)
			for(int j=0;j<10;j++)
				for(int t,k=0;k<10;k++){
					t=(s2[i]-s1[i]-j+20)%10;
					for(int a=0;a<=t;a++)
						for(int b=0;b<=a;b++)
							dp[i+1][(k+a)%10][b]=min(dp[i+1][(k+a)%10][b],dp[i][j][k]+t);
					t=(10-t)%10;
					for(int a=0;a<=t;a++)
						for(int b=0;b<=a;b++)
							dp[i+1][(k-a+10)%10][(10-b)%10]=min(dp[i+1][(k-a+10)%10][(10-b)%10],dp[i][j][k]+t);
				}
		cout << dp[len][0][0] << endl;
	}
	return 0;
}
