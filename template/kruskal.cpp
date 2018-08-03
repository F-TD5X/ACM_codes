#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e3+10;
struct E{
	int u,v,w;
	E(){}
	E(int u,int v,int w):u(u),v(v),w(w){}
};
vector<E> e;

int n,m;			//n = points, m = edges
int fa[maxn];

int F(int x){
	return x == fa[x] ? x : fa[x] = F(fa[x]);
}

bool cmp(E a,E b){
	return a.w < b.w;
}

void input(){
	cin >> n >> m;
	for(int u,v,w,i=0;i<m;i++){
		cin >> u >> v>> w;
		e.push_back(E(u,v,w));
	}
}

void init(){
	for(int i=1;i<maxn;i++)
		fa[i]=i;
	input();
	sort(e.begin(),e.end(),cmp);
}

void Kruskal(){
	int sum=0;
	int num=0;
	int u,v;
	init();
	for(int i=0;i<e.size();i++){
		u= F(e[i].u);
		v=F(e[i].v);
		if( u != v){
			printf("from:%d  to:%d  weight:%d\n",e[i].u,e[i].v,e[i].w);
			sum += e[i].w;
			fa[u] = fa[v];
		}
		if(num >= n-1) break;
	}
	printf("sum weight:%d\n",sum);
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("kruskal.in","r",stdin);
    //freopen("kruskal.out","w",stdout);
#endif

    return 0;
}
