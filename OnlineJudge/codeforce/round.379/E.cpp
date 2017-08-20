#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+10;
int cl[maxn];
int n;
vector<int> tree[maxn];
int deep=-1,p,u;

int dfs(int pre,int u,int n)
{
	if(n>deep)
	{
		p=u;
		deep=n;
	}
	for(auto b:tree[u])
	{
		if(b==pre)
			continue;
		dfs(u,b,n+(cl[b]!=cl[u]));
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%d",cl+i);
	for(int i=0,u,v;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(-1,1,1);
	deep=-1;
	dfs(-1,p,1);
	cout << deep/2<<endl;
	return 0;
}
