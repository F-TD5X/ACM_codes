#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char ma[1111][1111];
int k,x,y;
int ans,cas;
int move_k[8][2]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
int move_q[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
vector<pair<int,int>> Q;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m) && (n&&m))
	{
		cas++;
		ans=0;
		memset(ma,0,sizeof(ma));
		Q.clear();
		k=0;
		cin >> k;
		while(k--)
		{
			cin >> x>>y;
			ma[x][y]='Q';
			Q.push_back(make_pair(x,y));
		}
		k=0;
		cin >> k;
		while(k--)
		{
			cin >> x >> y;
			ma[x][y]='K';
			for(int i=0,xx,yy;i<8;i++)
			{
				xx=x+move_k[i][0];
				yy=y+move_k[i][1];
				if(!ma[xx][yy] && xx>=1 && xx<=n && yy>=1 && yy <=m)
					ma[xx][yy]='B';
			}
		}
		k=0;
		cin >> k;
		while(k--)
		{
			cin >> x >> y;
			ma[x][y]='P';
		}
		for(auto a:Q)
		{
			for(int i=0	,xx,yy;i<8;i++)
			{
				xx=a.first;yy=a.second;
				while(xx>=1&& xx<=n && yy>=1&& yy<=m )
				{
					if(ma[xx][yy]=='P' || ma[xx][yy]=='K')
						break;
					if(ma[xx][yy] != 'Q')
						ma[xx][yy]='B';
					xx+=move_q[i][0];
					yy+=move_q[i][1];
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans+=ma[i][j]==0?1:0;
		printf("Board %d has %d safe squares.\n",cas,ans);
	}
	return 0;
}
