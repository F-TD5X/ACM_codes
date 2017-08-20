#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n,m;
int mp[55][55];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--)
	{
		memset(mp,0,sizeof(mp));
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&mp[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(mp[i][j])
					ans++;
				for(int d=0;d<4;d++){
					if(mp[i+dx[d]][j+dy[d]] < mp[i][j])
						ans+=mp[i][j]-mp[i+dx[d]][j+dy[d]];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
