#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[111];
int topd[111];
int n,t;

int dfs(int u)
{
	c[u]=-1;
	for(int v=0;v<n;v++)
	{
		if(c[v]<0)
			return 0;
		else if(!c[v] && !dfs(v))
			return 0;
	}
	c[u]=1;
	topd[--t]=u;
	return 1;
}

int solve()
{
	t=n;
	for(int u=0;u<n;u++)
		if(!c[u])
			if(!dfs(u))
				return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa10305.in","r",stdin);
    //freopen("UVa10305.out","w",stdout);
#endif
	char c[111111];
	gets();
	return 0;
}
