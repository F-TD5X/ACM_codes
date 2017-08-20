#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1111;
int n,m,w;
int wei[maxn],b[maxn];
vector<int> mp[maxn];
int mp[maxn][maxn];
int fa[maxn];

int fi(int st)
{
	if(st!=fa[st])
		fa[st]=fi(fa[st]);
	return fa[st];
}

void uni(int v,int u)
{
	int xv=fi(v),xu=fi(u);
	if(xv!=xu)
		fa[xv]=xu;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	cin >> n>>m>>w;
	for(int i=0;i<n;i++)
		cin >>wei[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int x,y,i=0;i<m;i++)
	{
		cin >> x>>y;
		for(int i=x;i<=y;i++)
			uni(x,i);
	}

	return 0;
}
