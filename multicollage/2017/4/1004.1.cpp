/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=6e4+10;
struct Node
{
	int ls,rs,cnt;
}tree[maxn*20];

int cur,rt[maxn];


template <class T>
inline bool scan_d(T &ret)
{
	char c;
	int sgn;
	if (c = getchar(), c == EOF)
	{
		return 0; //EOF
	}
	while (c != '-' && (c < '0' || c > '9'))
	{
		c = getchar();
	}
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0' && c <= '9')
	{
		ret = ret * 10 + (c - '0');
	}
	ret *= sgn;
	return 1;
}

void init()
{
	cur=0;
	memset(tree,0,sizeof(tree));
}

inline void push_up(int st)
{
	tree[st].cnt=tree[tree[st].ls].cnt+tree[tree[st].rs].cnt;
}

int build(int l,int r)
{
	int k=cur++;
	if(l==r){
		tree[k].cnt=0;
		return k;
	}
	int mid=(l+r)>>1;
	tree[k].ls=build(l,mid);
	tree[k].rs=build(mid+1,r);
	push_up(k);
	return k;
}

int update(int st,int l,int r,int pos,int val)
{
	int k=cur++;
	tree[k]=tree[st];
	if(l==pos && r==pos){
		tree[k].cnt+=val;
		return k;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)
		tree[k].ls=update(tree[st].ls,l,mid,pos,val);
	else
		tree[k].rs=update(tree[st].rs,mid+1,r,pos,val);
	push_up(k);
	return k;
}

int query(int l,int r,int st,int pos)
{
	if(l==r) return tree[st].cnt;
	int mid=(l+r)>>1;
	if(pos<=mid)
		return tree[tree[st].rs].cnt+query(l,mid,tree[st].ls,pos);
	else
		return query(mid+1,r,tree[st].rs,pos);
}

int b[maxn];
map<int,int> mp;
int n;
int beg[maxn];
int cnt=0;
int mmp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1004.in","r",stdin);
    //freopen("1004.out","w",stdout);
#endif
	int T;
	scan_d(T);
	while(T--){
		mp.clear();
		init();
		scan_d(n);
		for(int i=1;i<=n;i++){
			scan_d(b[i]);
			if(beg[b[i]]==0){
				mmp[cnt++]=b[i];
				beg[b[i]]=i;
			}
		}
		rt[0]=build(1,n);
		for(int i=1;i<=n;i++){
			if(mp.find(b[i])==mp.end()){
				mp[b[i]]=i;
				rt[i]=update(rt[i-1],1,n,i,1);
			}
			else{
				int tmp=update(rt[i-1],1,n,mp[b[i]],-1);
				rt[i]=update(tmp,1,n,i,1);
			}
		}
		double ans=1;
		for(int i=0;i<cnt;i++){
			for(int j=i+1;j<cnt;j++){
					ans=min(ans,1.0*query(1,n,rt[beg[mmp[j]]-1],beg[mmp[i]])/(beg[mmp[j]]-beg[mmp[i]]));
					ans=min(ans,1.0*query(1,n,rt[n],beg[mmp[i]])/(n-beg[mmp[i]]+1));
			}
		}
		printf("%.6lf\n",ans);
	}

	return 0;
}
