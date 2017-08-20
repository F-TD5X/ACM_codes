#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int vi[100005];
struct node
{
	int k;
	int l;
	node(int k,int l):k(k),l(l){}
};
vector<node>v[100005];
int main()
{
	memset(vi,0,sizeof(vi));
	scanf("%d%d%d",&n,&m,&k);
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(node(b,c));
		v[b].push_back(node(a,c));
	}
	for(int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		vi[a]=1;
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		if(vi[i])
			continue;
		for(int j=0;j<v[i].size();j++)
		{
			if(vi[v[i][j].k])
			{
				if(ans==-1)
					ans=v[i][j].l;
				else
					ans=min(ans,v[i][j].l);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

