#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int k;
int mp[30][30];
int vis[30];
vector<int> ans;
int cnt;

int dfs(int x)
{
	if(x==k)
	{
		for(auto a:ans)
			cout << " " << a;
		cout <<endl;
		cnt++;
		return 0;
	}
	vis[x]=1;
	for(int i=0;i<30;i++)
	{
		if(mp[x][i] && !vis[i])
		{
			ans.push_back(i);
			dfs(i);
			ans.erase(--ans.end());
		}
	}
	vis[x]=0;	
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa208.in","r",stdin);
    //freopen("UVa208.out","w",stdout);
#endif
	int x,y,cas=1;
	while(cin >> k)
	{
		memset(vis,0,sizeof(vis));
		memset(mp,0,sizeof(mp));
		ans.clear();
		printf("CASE %d:\n",cas);
		while(cin >> x >> y  && x+y)
			mp[x][y]=mp[y][x]=1;
		ans.push_back(1);
		cnt=0;
		dfs(1);
		printf("There are %d routes from the firestation to streetcorner %d.\n",cnt,k);
	}
	return 0;
}
