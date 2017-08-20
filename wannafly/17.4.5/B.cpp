#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=4e5+5;
int n,m,dfn[maxn],low[maxn],head[maxn],e_cnt,tot;

void init()
{
	for(int i=1;i<n+1;i++)
		head[i]=-1;
	for(int i=1;i<n+1;i++)
		dfn[i]=low[i]=0;
	e_cnt=0;
}

struct Edge
{
	int u,v;
	int nt;
	Edge(){}
	Edge(int u,int v,int n):u(u),v(v),nt(n){}
}e[maxn<<1];

pair<int,int> mat[maxn];

void addedge(int u,int v,int w)
{
	e[e_cnt]=Edge(v,w,head[u]);
	head[u]=e_cnt++;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	
	return 0;
}
