#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111;
int ma[111][111];
int n,m;
int dp[111][111];
int nxt[111][111];
#define INF 0x3f3f3f3f

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("Uva116.in","r",stdin);
    //freopen("Uva116.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&ma[i][j]);
		memset(dp,0,sizeof(dp));
		int ans=INF,first=0;
		for(int j=n-1;j>=0;j--)
			for(int i=0;i<m;i++)
			{
				if(j==n-1)
					dp[i][j]=ma[i][j];
				else 
				{
					int row[3]={i,i-1,i+1};
					if(i==0)
						row[1]=m-1;
					if(i==n)
						row[2]=0;
					sort(row,row+3);
					dp[i][j]=INF;
					for(int k=0;k<3;k++)
					{
						int v=dp[row[k]][j+1]+ma[i][j];
						if(v<dp[i][j])
						{
							dp[i][j]=v;
							nxt[i][j]=row[k];
						}
					}
				}
				if(j==0 && dp[i][j]<ans)
				{
					ans=dp[i][j];
					first=i;
				}
			}
		cout <<first+1;
		for(int i=nxt[first][0],j=1;j<n;i=nxt[first][j],j++)
			cout << " " << i+1;
		cout << endl << ans<<endl;
	}
	return 0;
}
