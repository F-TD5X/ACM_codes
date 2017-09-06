/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+100;
int n,m,p;
int val[maxn];
vector<int> G[maxn];
int dep[maxn],siz[maxn],top[maxn],fa[maxn],son[maxn],pos[maxn];
int tot;
int c[maxn];

void init(){
	for(int i=0;i<=n;i++)
		G[i].clear();
	memset(son,-1,sizeof(son));
	memset(siz,0,sizeof(siz));
	tot=1;
	memset(c,0,sizeof(c));
}

void dfs1(int st,int f,int d){
	fa[st]=f;
	dep[st]=d;
	siz[st]++;
	for(auto v:G[st]){
		if(v!=f){
			dfs1(v,st,d+1);
			if(son[st]!=-1 || siz[v] > siz[son[st]]) son[st]=v;
			siz[st]+=siz[v];
		}
	}
}

void dfs2(int st,int f){
	top[st]=f;
	pos[st]=tot++;
	if(son[st]==-1)return;
	dfs2(son[st],f);
	for(auto v:G[st]){
		if(v!=fa[st] && v!=son[st])
			dfs2(v,v);
	}
}

int lowbit(int x){return x&-x;}

void update(int x,int val){
	while(x<=maxn){
		c[x]+=val;
		x+=lowbit(x);
	}
}

int query(int x){
	int ret=0;
	for(;x>0;x-=lowbit(x)) ret+=c[x];
	return ret;
}

void change(int s,int t,int c){
	int f1=top[s],f2=top[t];
	while(f1!=f2){
		if(dep[f1]<dep[f2]) swap(f1,f2),swap(s,t);
		update(pos[f1],c);
		update(pos[s]+1,-c);
		s=fa[f1];
		f1=top[s];
	}
	if(dep[s]>dep[t])
		swap(s,t);
	update(pos[s],c);
	update(pos[t]+1,-c);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("3966.in","r",stdin);
    //freopen("3966.out","w",stdout);
#endif
	while(~scanf("%d%d%d",&n,&m,&p)){
		init();
		for(int i=1;i<=n;i++)
			scanf("%d",val+i);
		for(int u,v,i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1,-1,1);
		dfs2(1,1);
		for(int i=1;i<=n;i++) update(pos[i],val[i]),update(pos[i]+1,-val[i]);
		char s[2];
		for(int c1,c2,k,i=0;i<p;i++){
			scanf("%s",s);
			if(s[0]=='Q'){
				scanf("%d",&c1);
				printf("%d\n",query(pos[c1]));
			}
			else{
				scanf("%d%d%d",&c1,&c2,&k);
				if(s[0]=='D')
					k=-k;
				change(c1,c2,k);
			}
		}
	}

	return 0;
}
