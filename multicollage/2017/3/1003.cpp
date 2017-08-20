/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int N=maxn-1;

struct BT{
	int C[maxn];
	inline int lowbit(int x){return x&(-x);}
	void init(){memset(C,0,sizeof(C));}
	int sum(int end){
		int ret=0;
		while(end>0){
			ret+=C[end];
			end-=lowbit(end);
		}
	}
	void modify(int p,int inc){
		while(p<=N){
			C[p]+=inc;
			p+=lowbit(p);
		}
	}
}bt;

struct Seg{
	struct seg{int cnt;} tree[maxn*2];
	int pLeaf[maxn];
	void init(){memset(tree,0,sizeof(tree));}
	void build(int a,int b,int k){
		if(a==b){
			pLeaf[a]=k;
			return;
		}
		int mid=(a+b)>>1;
		build(a,mid,k<<1);
		build(mid+1,b,k<<1|1);
	}
	void Update(int leaf,int inc){
		int k=pLeaf[leaf];
		while(k){
			tree[k].cnt+=inc;
			k>>=1;
		}
	}
	int query(int a,int b,int kth,int k){
		if(a==b)
			return a;
		int mid=(a+b)>>1;
		if(kth<=tree[k<<1].cnt)
			return query(a,mid,kth,k<<1);
		else
			return query(mid+1,b,kth,k<<1|1);
	}
}SegTree;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif

	return 0;
}
