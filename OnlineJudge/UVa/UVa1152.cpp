#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=4444;
int a[5][maxn],n;
int mp[maxn*maxn];
int cnt;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa1152.in","r",stdin);
    //freopen("UVa1152.out","w",stdout);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		scanf("%d",&n);
		memset(mp,0,sizeof(mp));
		int ans=0;
		cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<4;j++)
				scanf("%d",&a[j][i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				mp[cnt++]=a[0][i]+a[1][j];
		sort(mp,mp+cnt);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int t=-1*(a[2][i]+a[3][j]);
				ans+=upper_bound(mp,mp+cnt,t)-lower_bound(mp,mp+cnt,t);
			}
		printf("%d\n",ans);
		if(t)
			puts("");
	}
	return 0;
}
