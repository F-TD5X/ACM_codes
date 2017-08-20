#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dis[4][2]={1,0,0,1,0,-1,-1,0};
int c_dis[4]={'e','n','s','w'};
int n;
const int maxn=1e4+10;
int mp[maxn][maxn];
bool ok;
int route[maxn];
const int len=1e4/2;

void dfs(int x,int y,int d,int step)
{
	if(x==0&& y==0 && ok)
	{
		for(int i=0;i<step;i++)
			cout <<c_dis[route[i]];
		cout <<endl;
		return;
	}
	ok=1;
	for(int i=0;i<4;i++)
	{
		if(i!=d)
		{
			if(x+step*dis[i][0] < n+len && y+step*dis[i][0]<n+len && x+step*dis[i][0]>=n-len && y+step*dis[i][0]>=n-len)
			{
				bool flag=1;
				for(int j=1;j<=step;j++)
					if(mp[x+j*dis[i][0]][y]==1)
					{
						flag=0;
						break;
					}
				for(int j=1;j<=step;j++)
					if(mp[x][y+dis[i][1]*j]==1)
					{
						flag=0;
						break;
					}
				if(flag)
				{
					route[step]=i;
					dfs(x+step*dis[i][0],y+dis[i][1]*step,i,step+1);
				}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa225.in","r",stdin);
    //freopen("UVa225.out","w",stdout);
#endif
	int t;
	int b;
	cin >>t;
	while(t--)
	{
		cin >> n;
		cin >> b;
		for(int i=0,x,y;i<n;i++)
		{
			cin >> x>>y;
			mp[x+len][y+len]=1;
		}
		ok=0;
		dfs(len,len,0,0);
	}
	return 0;
}
