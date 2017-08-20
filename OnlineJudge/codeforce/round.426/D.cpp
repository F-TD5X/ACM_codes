/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=35000+10;
int n,k;
int a[maxn],f[maxn],pre[maxn],last[maxn];


struct SGT{
	int sum[maxn<<2],tag[maxn<<2];
	void init(){memset(sum,0,sizeof(sum));memset(tag,0,sizeof(tag));}
	void pushup(int st){
		sum[st]=max(sum[st<<1],sum[st<<1|1]);
	}
	void pushdown(int st){
		if(tag[st]){
			sum[st<<1]+=tag[st];
			sum[st<<1|1]+=tag[st];
			tag[st<<1]+=tag[st];
			tag[st<<1|1]+=tag[st];
			tag[st]=0;
		}
	}
	void build(int st,int l,int r){
		tag[st]=0;
		if(l==r){
			sum[st]=f[l];
			return;
		}
		int mid=(l+r)>>1;
		build(st<<1,l,mid);
		build(st<<1|1,mid+1,r);
		pushup(st);
	}
	void update(int L,int R,int l,int r,int st){
		if(L<=l && r<=R){
			sum[st]++;
			tag[st]++;
			return;
		}
		pushdown(st);
		int m=(l+r)>>1;
		if(L<=m) update(L,R,l,m,st<<1);
		if(m<R) update(L,R,m+1,r,st<<1|1);
		pushup(st);
	}
	int query(int L,int R,int l,int r,int st){
		if(L <= l && r<=R){
			return sum[st];
		}
		pushdown(st);
		int m=(l+r)>>1;
		if(R <= m)
			return query(L,R,l,m,st<<1);
		if(L > m)
			return query(L,R,m+1,r,st<<1|1);
		else
			return max(query(L,R,l,m,st<<1),query(L,R,m+1,r,st<<1|1));
	}
	void add(int x,int y,int l,int r,int st){
		if(l==r){
			sum[st]=y;
			return ;
		}
		pushdown(st);
		int mid=(l+r)>>1;
		if(x<=mid)
			add(x,y,l,mid,st<<1);
		else
			add(x,y,mid+1,r,st<<1|1);
		pushup(st);
	}
}sgt;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n >> k;
	sgt.init();
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=k;i++){
		sgt.build(1,0,n);
		for(int j=i;j<=n;j++){
			sgt.update(pre[j],j-1,0,n,1);
			f[j]=sgt.query(i-1,j-1,0,n,1);
		}
	}
	cout << f[n] << endl;

	return 0;
}
