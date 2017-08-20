#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int C[1000],A[1000];
int fa[1000];
vector<int> son[1000];

int x,y;
int T,n;
int ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif
	cin >>T;
	while(T--)	
	{
		cin >>n;
		for(int i=0;i<n+2;i++)
			son[i].clear();
		for(int i=0;i<n;i++)
		{
			cin >> x>>y;
			fa[y]=x;
			son[x].push_back(y);
		}
		for(int i=1;i<=n;i++)
		{
			cin >> x;
			C[i]=x;
		}
		for(int i=1;i<=n;i++)
		{
			cin >> x;
			A[i]=x;
		}

	}
	return 0;
}
