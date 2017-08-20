#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int pos[10000];
vector<int> G[10000];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa10410.in","r",stdin);
    //freopen("UVa10410.out","w",stdout);
#endif
	int x;
	while(cin >> n && n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> x;
			pos[x]=i;
			G[i].clear();
		}
		int root;
		cin >> root;
		stack<int> sta;
		sta.push(root);
		for(int i=1;i<n;i++)
		{
			cin >> x;
			while(1)
			{
				int u=sta.top();
				if(pos[u]+1 < pos[x] || (pos[u]+1==pos[x] && u>x)||u==root)
				{
					G[u].push_back(x);
					sta.push(x);
					break;
				}
				else
					sta.pop();
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout << i <<":";
			for(int j=0;j<G[i].size();j++)
				cout << " " << G[i][j];
			cout <<endl;
		}
	}
	return 0;
}
