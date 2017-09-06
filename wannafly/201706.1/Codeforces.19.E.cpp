/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;

struct Edge{
	int from,to,next;
}E[maxn<<1];

struct Line{
	int u,v;
}L[maxn];

int n,m,cnt,head[maxn],fa[maxn],col[maxn],son[maxn],siz[maxn],top[maxn],fa[maxn],dfn[maxn];
bool vis[maxn];

void init(){
	memset(head,-1,sizeof(head));
	cnt=1;
}

void addE(int from,int to){
	E[cnt].form=from;
	E[cnt].to=to;
	E[cnt].next=head[from];
	head[from]=cnt++;
}

void dfs1(int st,int ff){
	fa[st]=ff;siz[st]=1;son[st]=1;
	deep[st]==deep[ff]+1;
	for(int i=head[st];i!=-1;i=E[i].next){
		int to=E[i].to;
		if(deep[to])
			continue;
		col[to]=(i/2)+(i%2);
		vis[(i/2)+(i%2)]=1;
		dfs1(to,st);
		siz[st]+=siz[to];
		if(son[st]==-1 || siz[to]>siz[son[st]])
			son[st]=to;
	}
}

void dfs2(int st,int t){
	top[st]=t;
	dfn[st]=++tot;
	if(son[st]!=-1)
		dfs2(son[st],t);
	for(int i=head[st];i!=-1;i=E[i].next){
		int to=E[i].to;
		if(to== son[st]|| to== fa[st] || fa[to]!=st)
			continue;
		dfs2(to,to);
	}
}

int sum[maxn<<2],cov[maxn<<2],flag[maxn<<2];

void pushup(int st){
	sum[st]=sum[st<<1]+sum[st<<1|1];
}
void pushdown(int st,int l,int r){
	if(cov[st]){
		int mid=(l+r)>>1;
		cov[st<<1]+=cov[st];
		cov[st<<1|1]+=cov[st];
		sum[st<<1]+=(mid-l+1)*cov[st];
		sum[st<<1|1]+=(r-mid)*cov[st];
		cov[st]=0;
	}
}

void update(int L,int R,int l,int r,int st){
	if(L <=l && r<=R){
		cov[st]++;
		sum[st]+=r-l+1;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(st,l,r);
	if(L<=mid)
		update(L,R,l,mid,st<<1);
	if(R>mid)
		update(L,R,mid+1,r,st<<1|1);
	pushup(st);
}

void update2(int L,int R,int l,int r,int st){
	if(flag[st])return;
	if(L<=l && r<=R){
		flag[st]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)update2(L,R,l,mid,st<<1);
	if(R>mid)update2(L,R,mid+1,R,st<<1|1);
	pushup(st);
}

void Update(int x,int y,int tag){
	if(deep[x]<deep[y])
		swap(x,y);
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		int l=dfn[top[x]],r=dfn[top[y]];
		if(tag)
			update(l,r,1,n,1);
		else 
			update2(l,r,1,n,1);
		x=fa[top[x]];
	}
	if(x==y)
		return;
	if(deep[x]>deep[y])
		swap(x,y);
	int l=dfn[x]+1,r=dfn[y];
	if(tag)
		update(l,r,1,n,1);
	else
		update2(l,r,1,n,1);
}

int query(int p,int l,int r,int st){
	if(l==r)
		return sum[st];
	int mid=(l+r)>>1;
	pushdown(st,l,r);
	if(p<=mid)
		return query(p,l,mid,st<<1);
	else
		return query(p,mid+1,r,st<<1|1);
}

bool query2(int p,int l,int r,int st){
	if(flag[st])return 1;
	if(l==r) return 0;
	int mid=(l+r)>>1;
	if(p<=mid)
		return query2(p,l,mid,st<<1);
	else
		return query2(p,mid+1,r,st<<1|1);
}

int sta[maxn];
int T;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("Codeforces.19.E.in","r",stdin);
    //freopen("Codeforces.19.E.out","w",stdout);
#endif
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addE(u,v);addE(v,u);
		L[
	}

	return 0;
}
