#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=5e3+10;
const int INF=0x3f3f3f3f;

char p[maxn],q[maxn];
int sp[26],sq[26],ep[26],eq[26];
int dp[2][maxn],c[2][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1625.in","r",stdin);
    //freopen("1625.out","w",stdout);
#endif
	int T;
	cin >> T;
	while(T--)
	{
		scanf("%s%s",p+1,q+1);
		int n=strlen(p+1),m=strlen(q+1);
		for(int i=1;i<=n;i++)
			p[i]-='A';
		for(int i=1;i<=m;i++)
			q[i]-='A';
		for(int i=0;i<26;i++)
		{
			sp[i]=sq[i]=INF;
			ep[i]=eq[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			sp[p[i]]=min(sp[p[i]],i);
			ep[p[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			sq[q[i]]=min(sq[q[i]],i);
			eq[q[i]]=i;
		}
		int t=0;
		memset(c,0,sizeof(c));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n;i++,t^=1)
		{
			for(int j=0;j<=m;j++)
			{
				if(!i&&!j)
					continue;
				int v1=INF,v2=INF;
				if(i)
					v1=dp[t^1][j]+c[t^1][j];
				if(j)
					v2=dp[t][j-1]+c[t][j-1];
				dp[t][j]=min(v1,v2);
				if(i)
				{
					c[t][j]=c[t^1][j];
					if(sp[p[i]]==i && sq[p[i]]>j)
						c[t][j]++;
					if(ep[p[i]]==i && eq[p[i]]<=j)
						c[t][j]--;
				}
				else if(j)
				{
					c[t][j]=c[t][j-1];
					if(sq[q[j]]==j && sp[q[j]]>i)
						c[t][j]++;
					if(eq[q[j]]==j && ep[q[j]]<=i)
						c[t][j]--;
				}
			}
		}
		cout << dp[t^1][m]<<endl;
	}
	return 0;
}
