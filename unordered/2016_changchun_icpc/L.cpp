#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int mp[60][60];
ll ans;
int n,m;
int dir[4][2]={0,1,0,-1,-1,0,1,0};

int main()
{
#ifndef ONLINE_JUDGE
   	//freopen("L.in","r",stdin);
    //freopen("L.out","w",stdout);
#endif
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		ll cnt=0;
		ans=0;
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin >>mp[i][j];
				if(mp[i][j])
					cnt++;
			}
		ans+=cnt;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(!mp[i][j])
					continue;
				for(int k=0;k<4;k++)
				{
					int dx=i+dir[k][1],dy=j+dir[k][0];
					if(mp[dx][dy]>mp[i][j])
						continue;
					ans+=mp[i][j]-mp[dx][dy];
				}
			}
		cout <<ans<<endl;
	}
	return 0;
}
