#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	double x,y,r;
}p[1020];
int n;
bool vis[1020],flag;
double in,out;

void dfs(int u)
{
	if(!flag)
		return;
	vis[u]=1;
	if(p[u].y-p[u].r<=0){
		flag=0;return;
	}
	for(int v=0;v<n;v++){
		if(!vis[v] && hypot(p[u].x-p[v].x,p[u].y-p[v].y) < p[u].r+p[v].r)
			dfs(v);
		if(p[u].x -p[u].r <=0)
			in=min(in,p[u].y-sqrt(p[u].r*p[u].r-p[u].x*p[u].x));
		if(p[u].x+p[u].r>=1000)
			out=min(out,p[u].y-sqrt(p[u].r*p[u].r-(1000-p[u].r)*(1000-p[u].x)));
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa11853.in","r",stdin);
    //freopen("UVa11853.out","w",stdout);
#endif
	while(~scanf("%d",&n))
	{
		memset(vis,0,sizeof(vis));
		flag=1;
		in=out=1000;
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].r);
		for(int i=0;i<n;i++)
			if(!vis[i] && p[i].y+p[i].r>=1000)
				dfs(i);
		if(!flag)
			puts("IMPOSSIBLE");
		else
			printf("%.2lf %.2lf %.2lf %.2lf\n",0.0,in,1000.0,out);
	}
	return 0;
}
