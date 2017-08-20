<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
const int maxn=4e5;
int tree[maxn],mark[maxn],lazy[maxn];

void PushUp(int st)
{
	tree[st]=tree[st<<1]+tree[st<<1|1];
	if(mark[st<<1] == mark[st<<1|1])
		mark[st] = mark[st<<1];
	else
		mark[st]=0;
}

void PushDown(int st,int len)
{
	if(mark[st]) {
		mark[st<<1]=mark[st<<1|1] = mark[st];
		tree[st<<1]=mark[st]*(len-len/2);
		tree[st<<1|1]=mark[st]*(len/2);
		lazy[st]=0;
	}
	if(lazy[st]) {
		lazy[st<<1]+=lazy[st];
		lazy[st<<1|1]+=lazy[st];
		tree[st<<1]+=lazy[st]*(len-len/2);
		tree[st<<1|1]+=lazy[st]*len/2;
		if(mark[st<<1])
			mark[st<<1]+=lazy[st];
		if(mark[st<<1|1])
			mark[st<<1|1]+=lazy[st];
		lazy[st]=0;
	}
}

void build(int st,int l,int r)
{
	mark[st]=0;
	lazy[st]=0;
	if(l==r) {scanf("%d",&tree[st]);mark[st]=tree[st];}
	else {
		build(st<<1,l,(l+r)/2);
		build(st<<1|1,(l+r)/2+1,r);
		tree[st]=tree[st<<1]+tree[st<<1|1];
	}
}

void oper1(int st,int l,int r,int L,int R,int a)
{
	if(l>R || r<L)
		return;
	if(l>=L && r<=R) {
		tree[st]+=a*(r-l+1);
		lazy[st]+=a;
		if(mark[st])
			mark[st]+=a;
		return;
	}
	PushDown(st,r-l+1);
	if(L<=(l+r)/2)
		oper1(st<<1,l,(l+r)/2,L,R,a);
	if((l+r)/2<R)
		oper1(st<<1|1,(l+r)/2+1,r,L,R,a);
	PushUp(st);
}

void oper2(int st,int l,int r,int L,int R)
{
	if(l>R || r<L) return;
	if(L<=l && r<=R && mark[st]) {
		mark[st]=sqrt(mark[st]);
		tree[st]=mark[st]*(r-l+1);
		return;
	}
	PushDown(st,r-l+1);
	if(L<=(l+r)/2)
		oper2(st<<1,l,(l+r)/2,L,R);
	if((l+r)/2<R)
	oper2(st<<1|1,(l+r)/2+1,r,L,R);
	PushUp(st);
}

int getAns(int st,int l,int r,int L,int R)
{
	if(l>R || r<L)
		return 0;
	if(l>=L && r<=R)
		return tree[st];
	PushUp(st);
	return getAns(st<<1,l,(l+r)/2,L,R)+getAns(st<<1|1,(l+r)/2+1,r,L,R);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	scanf("%d",&T);
	int c,l,r,a,n,m;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		build(1,1,n);
		while(m--)
		{
			scanf("%d%d%d",&c,&l,&r);
			if(c==1) {
				scanf("%d",&a);
				oper1(1,1,n,l,r,a);
			}
			else if(c==2)
				oper2(1,1,n,l,r);
			else if(c==3)
				printf("%d\n", getAns(1,1,n,l,r));
		}
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
const int maxn=4e5;
int tree[maxn],mark[maxn],lazy[maxn];

void PushUp(int st)
{
	tree[st]=tree[st<<1]+tree[st<<1|1];
	if(mark[st<<1] == mark[st<<1|1])
		mark[st] = mark[st<<1];
	else
		mark[st]=0;
}

void PushDown(int st,int len)
{
	if(mark[st]) {
		mark[st<<1]=mark[st<<1|1] = mark[st];
		tree[st<<1]=mark[st]*(len-len/2);
		tree[st<<1|1]=mark[st]*(len/2);
		lazy[st]=0;
	}
	if(lazy[st]) {
		lazy[st<<1]+=lazy[st];
		lazy[st<<1|1]+=lazy[st];
		tree[st<<1]+=lazy[st]*(len-len/2);
		tree[st<<1|1]+=lazy[st]*len/2;
		if(mark[st<<1])
			mark[st<<1]+=lazy[st];
		if(mark[st<<1|1])
			mark[st<<1|1]+=lazy[st];
		lazy[st]=0;
	}
}

void build(int st,int l,int r)
{
	mark[st]=0;
	lazy[st]=0;
	if(l==r) {scanf("%d",&tree[st]);mark[st]=tree[st];}
	else {
		build(st<<1,l,(l+r)/2);
		build(st<<1|1,(l+r)/2+1,r);
		tree[st]=tree[st<<1]+tree[st<<1|1];
	}
}

void oper1(int st,int l,int r,int L,int R,int a)
{
	if(l>R || r<L)
		return;
	if(l>=L && r<=R) {
		tree[st]+=a*(r-l+1);
		lazy[st]+=a;
		if(mark[st])
			mark[st]+=a;
		return;
	}
	PushDown(st,r-l+1);
	if(L<=(l+r)/2)
		oper1(st<<1,l,(l+r)/2,L,R,a);
	if((l+r)/2<R)
		oper1(st<<1|1,(l+r)/2+1,r,L,R,a);
	PushUp(st);
}

void oper2(int st,int l,int r,int L,int R)
{
	if(l>R || r<L) return;
	if(L<=l && r<=R && mark[st]) {
		mark[st]=sqrt(mark[st]);
		tree[st]=mark[st]*(r-l+1);
		return;
	}
	PushDown(st,r-l+1);
	if(L<=(l+r)/2)
		oper2(st<<1,l,(l+r)/2,L,R);
	if((l+r)/2<R)
	oper2(st<<1|1,(l+r)/2+1,r,L,R);
	PushUp(st);
}

int getAns(int st,int l,int r,int L,int R)
{
	if(l>R || r<L)
		return 0;
	if(l>=L && r<=R)
		return tree[st];
	PushUp(st);
	return getAns(st<<1,l,(l+r)/2,L,R)+getAns(st<<1|1,(l+r)/2+1,r,L,R);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	scanf("%d",&T);
	int c,l,r,a,n,m;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		build(1,1,n);
		while(m--)
		{
			scanf("%d%d%d",&c,&l,&r);
			if(c==1) {
				scanf("%d",&a);
				oper1(1,1,n,l,r,a);
			}
			else if(c==2)
				oper2(1,1,n,l,r);
			else if(c==3)
				printf("%d\n", getAns(1,1,n,l,r));
		}
	}
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
const int maxn=4e5;
int tree[maxn],mark[maxn],lazy[maxn];

void PushUp(int st)
{
	tree[st]=tree[st<<1]+tree[st<<1|1];
	if(mark[st<<1] == mark[st<<1|1])
		mark[st] = mark[st<<1];
	else
		mark[st]=0;
}

void PushDown(int st,int len)
{
	if(mark[st]) {
		mark[st<<1]=mark[st<<1|1] = mark[st];
		tree[st<<1]=mark[st]*(len-len/2);
		tree[st<<1|1]=mark[st]*(len/2);
		lazy[st]=0;
	}
	if(lazy[st]) {
		lazy[st<<1]+=lazy[st];
		lazy[st<<1|1]+=lazy[st];
		tree[st<<1]+=lazy[st]*(len-len/2);
		tree[st<<1|1]+=lazy[st]*len/2;
		if(mark[st<<1])
			mark[st<<1]+=lazy[st];
		if(mark[st<<1|1])
			mark[st<<1|1]+=lazy[st];
		lazy[st]=0;
	}
}

void build(int st,int l,int r)
{
	mark[st]=0;
	lazy[st]=0;
	if(l==r) {scanf("%d",&tree[st]);mark[st]=tree[st];}
	else {
		build(st<<1,l,(l+r)/2);
		build(st<<1|1,(l+r)/2+1,r);
		tree[st]=tree[st<<1]+tree[st<<1|1];
	}
}

void oper1(int st,int l,int r,int L,int R,int a)
{
	if(l>R || r<L)
		return;
	if(l>=L && r<=R) {
		tree[st]+=a*(r-l+1);
		lazy[st]+=a;
		if(mark[st])
			mark[st]+=a;
		return;
	}
	PushDown(st,r-l+1);
	if(L<=(l+r)/2)
		oper1(st<<1,l,(l+r)/2,L,R,a);
	if((l+r)/2<R)
		oper1(st<<1|1,(l+r)/2+1,r,L,R,a);
	PushUp(st);
}

void oper2(int st,int l,int r,int L,int R)
{
	if(l>R || r<L) return;
	if(L<=l && r<=R && mark[st]) {
		mark[st]=sqrt(mark[st]);
		tree[st]=mark[st]*(r-l+1);
		return;
	}
	PushDown(st,r-l+1);
	if(L<=(l+r)/2)
		oper2(st<<1,l,(l+r)/2,L,R);
	if((l+r)/2<R)
	oper2(st<<1|1,(l+r)/2+1,r,L,R);
	PushUp(st);
}

int getAns(int st,int l,int r,int L,int R)
{
	if(l>R || r<L)
		return 0;
	if(l>=L && r<=R)
		return tree[st];
	PushUp(st);
	return getAns(st<<1,l,(l+r)/2,L,R)+getAns(st<<1|1,(l+r)/2+1,r,L,R);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	scanf("%d",&T);
	int c,l,r,a,n,m;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		build(1,1,n);
		while(m--)
		{
			scanf("%d%d%d",&c,&l,&r);
			if(c==1) {
				scanf("%d",&a);
				oper1(1,1,n,l,r,a);
			}
			else if(c==2)
				oper2(1,1,n,l,r);
			else if(c==3)
				printf("%d\n", getAns(1,1,n,l,r));
		}
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
