<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
int arr[maxn<<2];
struct Node
{
	ll min,max,sum,add;
	void update(int l,int r,ll x) {
		add+=x,min+=x,max+=x;sum+=x*(r-l+1);
	}
}tree[maxn<<2];

int n,m,PPT;

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
void Out(ll a)
{
    if(a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

inline void PushUp(int st,int l,int r) 
{
	tree[st].min=min(tree[st<<1].min,tree[st<<1|1].min)+tree[st].add;
	tree[st].max=max(tree[st<<1].max,tree[st<<1|1].max)+tree[st].add;
	tree[st].sum=tree[st<<1].sum+tree[st<<1|1].sum+tree[st].add*(r-l+1);
}

void build(int st,int l,int r)
{
	tree[st].add=tree[st].min=tree[st].max=tree[st].sum=0;	
	if(l==r) {	
		scan_d(PPT);
		tree[st].min=tree[st].max=tree[st].sum=PPT;
		return;
	}
	build(st<<1,l,(l+r)/2);
	build(st<<1|1,(l+r)/2+1,r);
	PushUp(st,l,r);
}

inline ll Ask(int st, int l, int r, int L, int R, ll add) {
	ll ret = 0;
	if (L <= l&&r <= R)
		return tree[st].sum + add*(r - l + 1);
	if (L <= (l+r)/2)
		ret += Ask(st << 1, l, (l+r)/2, L, R, add + tree[st].add);
	if (R>(l+r)/2)
		ret += Ask(st << 1 | 1, (l+r)/2 + 1, r, L, R, add + tree[st].add);
	return ret;
}

void Sqrt(int st,int l,int r,int L,int R,ll tag) {
	if(L<=l && r<=R) {
    	if (tree[st].min==tree[st].max  || tree[st].max-tree[st].min==(ll)sqrt(tree[st].max+tag)-(ll)sqrt(tree[st].min+tag)) {
			ll ad=(ll)sqrt(tree[st].min+tag)-tree[st].min-tag;
			tree[st].update(l,r,ad);
			return;
		}
		Sqrt(st<<1,l,(l+r)/2,L,R,tag+tree[st].add);
		Sqrt(st<<1|1,(l+r)/2+1,r,L,R,tag+tree[st].add);
		PushUp(st,l,r);
		return;
	}
	if(L<=(l+r)/2)
		Sqrt(st<<1,l,(l+r)/2,L,R,tag+tree[st].add);
	if(R>(l+r)/2)
		Sqrt(st<<1|1,(l+r)/2+1,r,L,R,tag+tree[st].add);
	PushUp(st,l,r);  
}  

inline void Add(int st, int l, int r, int L, int R, ll tag) {
	if (L <= l&&r <= R) {
		tree[st].update(l, r, tag);
		return;
	}
	if (L <= (l+r)/2)
		Add(st << 1, l, (l+r)/2, L, R, tag);
	if (R>(l+r)/2)
		Add(st << 1 | 1, (l+r)/2 + 1, r, L, R, tag);
	PushUp(st, l, r);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B_1.in","r",stdin);
    //freopen("B_1.out","w",stdout);
#endif
	int t;
	scan_d(t);
	while(t--){
		scan_d(n);
		scan_d(m);
		build(1,1,n);
		int c,a,b,add;
		while(m--) {
			//scanf("%d%d%d",&c,&a,&b);
			scan_d(c);
			scan_d(a);
			scan_d(b);
			if(c==1) {
				//scanf("%d",&add);
				scan_d(add);
				Add(1,1,n,a,b,add);
			}
			if(c==2)
				Sqrt(1,1,n,a,b,0);
			if(c==3)
				Out(Ask(1,1,n,a,b,0)),puts("");
		}
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
int arr[maxn<<2];
struct Node
{
	ll min,max,sum,add;
	void update(int l,int r,ll x) {
		add+=x,min+=x,max+=x;sum+=x*(r-l+1);
	}
}tree[maxn<<2];

int n,m,PPT;

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
void Out(ll a)
{
    if(a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

inline void PushUp(int st,int l,int r) 
{
	tree[st].min=min(tree[st<<1].min,tree[st<<1|1].min)+tree[st].add;
	tree[st].max=max(tree[st<<1].max,tree[st<<1|1].max)+tree[st].add;
	tree[st].sum=tree[st<<1].sum+tree[st<<1|1].sum+tree[st].add*(r-l+1);
}

void build(int st,int l,int r)
{
	tree[st].add=tree[st].min=tree[st].max=tree[st].sum=0;	
	if(l==r) {	
		scan_d(PPT);
		tree[st].min=tree[st].max=tree[st].sum=PPT;
		return;
	}
	build(st<<1,l,(l+r)/2);
	build(st<<1|1,(l+r)/2+1,r);
	PushUp(st,l,r);
}

inline ll Ask(int st, int l, int r, int L, int R, ll add) {
	ll ret = 0;
	if (L <= l&&r <= R)
		return tree[st].sum + add*(r - l + 1);
	if (L <= (l+r)/2)
		ret += Ask(st << 1, l, (l+r)/2, L, R, add + tree[st].add);
	if (R>(l+r)/2)
		ret += Ask(st << 1 | 1, (l+r)/2 + 1, r, L, R, add + tree[st].add);
	return ret;
}

void Sqrt(int st,int l,int r,int L,int R,ll tag) {
	if(L<=l && r<=R) {
    	if (tree[st].min==tree[st].max  || tree[st].max-tree[st].min==(ll)sqrt(tree[st].max+tag)-(ll)sqrt(tree[st].min+tag)) {
			ll ad=(ll)sqrt(tree[st].min+tag)-tree[st].min-tag;
			tree[st].update(l,r,ad);
			return;
		}
		Sqrt(st<<1,l,(l+r)/2,L,R,tag+tree[st].add);
		Sqrt(st<<1|1,(l+r)/2+1,r,L,R,tag+tree[st].add);
		PushUp(st,l,r);
		return;
	}
	if(L<=(l+r)/2)
		Sqrt(st<<1,l,(l+r)/2,L,R,tag+tree[st].add);
	if(R>(l+r)/2)
		Sqrt(st<<1|1,(l+r)/2+1,r,L,R,tag+tree[st].add);
	PushUp(st,l,r);  
}  

inline void Add(int st, int l, int r, int L, int R, ll tag) {
	if (L <= l&&r <= R) {
		tree[st].update(l, r, tag);
		return;
	}
	if (L <= (l+r)/2)
		Add(st << 1, l, (l+r)/2, L, R, tag);
	if (R>(l+r)/2)
		Add(st << 1 | 1, (l+r)/2 + 1, r, L, R, tag);
	PushUp(st, l, r);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B_1.in","r",stdin);
    //freopen("B_1.out","w",stdout);
#endif
	int t;
	scan_d(t);
	while(t--){
		scan_d(n);
		scan_d(m);
		build(1,1,n);
		int c,a,b,add;
		while(m--) {
			//scanf("%d%d%d",&c,&a,&b);
			scan_d(c);
			scan_d(a);
			scan_d(b);
			if(c==1) {
				//scanf("%d",&add);
				scan_d(add);
				Add(1,1,n,a,b,add);
			}
			if(c==2)
				Sqrt(1,1,n,a,b,0);
			if(c==3)
				Out(Ask(1,1,n,a,b,0)),puts("");
		}
	}
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
int arr[maxn<<2];
struct Node
{
	ll min,max,sum,add;
	void update(int l,int r,ll x) {
		add+=x,min+=x,max+=x;sum+=x*(r-l+1);
	}
}tree[maxn<<2];

int n,m,PPT;

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
void Out(ll a)
{
    if(a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

inline void PushUp(int st,int l,int r) 
{
	tree[st].min=min(tree[st<<1].min,tree[st<<1|1].min)+tree[st].add;
	tree[st].max=max(tree[st<<1].max,tree[st<<1|1].max)+tree[st].add;
	tree[st].sum=tree[st<<1].sum+tree[st<<1|1].sum+tree[st].add*(r-l+1);
}

void build(int st,int l,int r)
{
	tree[st].add=tree[st].min=tree[st].max=tree[st].sum=0;	
	if(l==r) {	
		scan_d(PPT);
		tree[st].min=tree[st].max=tree[st].sum=PPT;
		return;
	}
	build(st<<1,l,(l+r)/2);
	build(st<<1|1,(l+r)/2+1,r);
	PushUp(st,l,r);
}

inline ll Ask(int st, int l, int r, int L, int R, ll add) {
	ll ret = 0;
	if (L <= l&&r <= R)
		return tree[st].sum + add*(r - l + 1);
	if (L <= (l+r)/2)
		ret += Ask(st << 1, l, (l+r)/2, L, R, add + tree[st].add);
	if (R>(l+r)/2)
		ret += Ask(st << 1 | 1, (l+r)/2 + 1, r, L, R, add + tree[st].add);
	return ret;
}

void Sqrt(int st,int l,int r,int L,int R,ll tag) {
	if(L<=l && r<=R) {
    	if (tree[st].min==tree[st].max  || tree[st].max-tree[st].min==(ll)sqrt(tree[st].max+tag)-(ll)sqrt(tree[st].min+tag)) {
			ll ad=(ll)sqrt(tree[st].min+tag)-tree[st].min-tag;
			tree[st].update(l,r,ad);
			return;
		}
		Sqrt(st<<1,l,(l+r)/2,L,R,tag+tree[st].add);
		Sqrt(st<<1|1,(l+r)/2+1,r,L,R,tag+tree[st].add);
		PushUp(st,l,r);
		return;
	}
	if(L<=(l+r)/2)
		Sqrt(st<<1,l,(l+r)/2,L,R,tag+tree[st].add);
	if(R>(l+r)/2)
		Sqrt(st<<1|1,(l+r)/2+1,r,L,R,tag+tree[st].add);
	PushUp(st,l,r);  
}  

inline void Add(int st, int l, int r, int L, int R, ll tag) {
	if (L <= l&&r <= R) {
		tree[st].update(l, r, tag);
		return;
	}
	if (L <= (l+r)/2)
		Add(st << 1, l, (l+r)/2, L, R, tag);
	if (R>(l+r)/2)
		Add(st << 1 | 1, (l+r)/2 + 1, r, L, R, tag);
	PushUp(st, l, r);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B_1.in","r",stdin);
    //freopen("B_1.out","w",stdout);
#endif
	int t;
	scan_d(t);
	while(t--){
		scan_d(n);
		scan_d(m);
		build(1,1,n);
		int c,a,b,add;
		while(m--) {
			//scanf("%d%d%d",&c,&a,&b);
			scan_d(c);
			scan_d(a);
			scan_d(b);
			if(c==1) {
				//scanf("%d",&add);
				scan_d(add);
				Add(1,1,n,a,b,add);
			}
			if(c==2)
				Sqrt(1,1,n,a,b,0);
			if(c==3)
				Out(Ask(1,1,n,a,b,0)),puts("");
		}
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
