#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ma[1111][1111];
int n,m,q;
int co,x,y,cl;
int mp[1111];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int t;
	cin >> t;
	while(t--)
	{
	scanf("%d%d%d",&n,&m,&q);
	memset(ma,0,sizeof(ma));
	for(int i=0;i<=n;i++)
		mp[i]=i;
	while(q--)
	{
		scanf("%d",&co);
		if(co==1)
		{
			scanf("%d%d%d",&cl,&x,&y);
			ma[mp[x]][y]=cl;
		}
		else
		{
			scanf("%d%d",&x,&y);
			int t=mp[x];
			mp[x]=mp[y];
			mp[y]=t;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ma[mp[i]][j]==0)
				putchar('.');
			else if(ma[mp[i]][j]==1)
				putchar('w');
			else
				putchar('b');
		}
		puts("");
	}
	}
	return 0;
}
