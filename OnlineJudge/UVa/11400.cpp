#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e4+10;
struct Node
{
	int v,k,c,l;
	bool operator<(const Node t) const
	{
		return v<t.v;
	}
}lamp[maxn];

int dp[maxn],s[maxn];
int n;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("11400.in","r",stdin);
    //freopen("11400.out","w",stdout);
#endif
	while(cin >> n && n)
	{
		for(int i=1;i<=n;i++)
			cin >> lamp[i].v>>lamp[i].k>>lamp[i].c>>lamp[i].l;
		sort(lamp+1,lamp+n+1);
		s[0]=0;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+lamp[i].l;
		for(int i=1;i<=n;i++)
		{
			dp[i]=s[i]*lamp[i].c+lamp[i].k;
			for(int j=1;j<=i;j++)
				dp[i]=min(dp[j]+(s[i]-s[j])*lamp[i].c+lamp[i].k,dp[i]);
		}
		cout <<dp[n]<<endl;
	}
	return 0;
}
