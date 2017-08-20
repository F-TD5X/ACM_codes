#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int mp[30][30];
int vis[30][30];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa1600.in","r",stdin);
    //freopen("UVa1600.out","w",stdout);
#endif
	while(cin >> n >> m)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >>mp[i][j];

	}
	return 0;
}
