#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &t) const{
		return w>t.w;
	}
}e[maxn];
int fa[maxn];
int cy[maxn];
int sum,ans;
int n,m;
int ext;

void init(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
		cy[i]=0;
	}
}

int fi(int x){
	return fa[x]==x?fa[x]:fa[x]=fi(fa[x]);
}

void kruskal(int n,int m){
	int a,b,k=0;
	sum=0;
	init();
	sort(e,e+m);
	for(int i=0;i<m;i++){
		a=fi(e[i].u);
		b=fi(e[i].v);
		if(a!=b && (cy[a]!=1 || cy[b]!=1)){
			sum+=e[i].w;
			fa[a]=b;
			if(cy[a])
				cy[b]=cy[a];
			ext=min(ext,e[i].w);
		}
		else if(cy[a]==0){
			sum+=e[i].w;
			cy[a]=1;
			ext=min(ext,e[i].w);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m) && n+m){
		ans=0;
		sum=0;
		ext=0x3f3f3f3f;
		for(int u,v,w,i=0;i<m;i++){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			ans+=e[i].w;
		}
		kruskal(n,m);
		printf("%d\n",ans-sum+ext);
	}

	return 0;
}
