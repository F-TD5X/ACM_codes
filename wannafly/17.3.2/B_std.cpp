<<<<<<< HEAD
<<<<<<< HEAD
#include<cstdio>  
#include<cstdlib>  
#include<algorithm>  
#include<cmath>  
#define mid ((l+r)>>1)  
using namespace std;  
typedef long long ll;  
  
  
const int N=100005;  
struct node{  
  ll min,max,sum,add;  
  void upd(int l,int r,ll x){  
    add+=x,min+=x,max+=x;  
    sum+=x*(r-l+1);  
  }  
}T[N<<2];  
  
inline void Pushup(int x,int l,int r) {  
  T[x].min=min(T[x<<1].min,T[x<<1|1].min)+T[x].add;  
  T[x].max=max(T[x<<1].max,T[x<<1|1].max)+T[x].add;  
  T[x].sum=T[x<<1].sum+T[x<<1|1].sum+T[x].add*(r-l+1);  
}  
  
inline void Sqrt(int x,int l,int r,int ql,int qr,ll tag) {  
  if(ql<=l && r<=qr) {  
    if (T[x].min==T[x].max  || T[x].max-T[x].min==(ll)sqrt(T[x].max+tag)-(ll)sqrt(T[x].min+tag)) {  
      ll ad=(ll)sqrt(T[x].min+tag)-T[x].min-tag;  
      T[x].upd(l,r,ad);  
      return;  
    }  
    Sqrt(x<<1,l,mid,ql,qr,tag+T[x].add),Sqrt(x<<1|1,mid+1,r,ql,qr,tag+T[x].add);  
    Pushup(x,l,r);  
    return;  
  }  
  if(ql<=mid) Sqrt(x<<1,l,mid,ql,qr,tag+T[x].add);  
  if(qr>mid) Sqrt(x<<1|1,mid+1,r,ql,qr,tag+T[x].add);  
  Pushup(x,l,r);  
}  
  
inline void Add(int x,int l,int r,int ql,int qr,ll tag) {  
  if(ql<=l&&r<=qr){  
    T[x].upd(l,r,tag);  
    return;  
  }  
  if(ql<=mid)  
    Add(x<<1,l,mid,ql,qr,tag);  
  if(qr>mid)  
    Add(x<<1|1,mid+1,r,ql,qr,tag);  
  Pushup(x,l,r);  
}  
  
inline ll Query(int x,int l,int r,int ql,int qr,ll add) {  
  ll ret=0;  
  if(ql<=l&&r<=qr)  
    return T[x].sum+add*(r-l+1);  
  if(ql<=mid)  
    ret+=Query(x<<1,l,mid,ql,qr,add+T[x].add);  
  if(qr>mid)  
    ret+=Query(x<<1|1,mid+1,r,ql,qr,add+T[x].add);  
  return ret;  
}  
  
int n;  
int Val[N];  
  
inline void Build(int x,int l,int r) {  
	T[x].min=T[x].max=T[x].sum=0;
  if(l==r){ T[x].min=T[x].max=T[x].sum=Val[l]; return; }  
  Build(x<<1,l,mid),Build(x<<1|1,mid+1,r);  
  Pushup(x,l,r);  
}  
  
int main(){ int PT;
	scanf("%d",&PT);
while(PT--)
{	
 	int Q; int order,l,r,t;  
 	scanf("%d%d",&n,&Q);
 	for (int i=1;i<=n;i++) scanf("%d",&Val[i]);  
 	Build(1,1,n);  
	while (Q--){  
		scanf("%d%d%d",&order,&l,&r);
	    if (order==1){  
			scanf("%d",&t);
	    	Add(1,1,n,l,r,t);  
	    }
		else if (order==2){  
	    	Sqrt(1,1,n,l,r,0);  
	    }
		else{  
	    	printf("%lld\n",Query(1,1,n,l,r,0));  
		}  
	}  
}
  return 0;  
}  
=======
#include<cstdio>  
#include<cstdlib>  
#include<algorithm>  
#include<cmath>  
#define mid ((l+r)>>1)  
using namespace std;  
typedef long long ll;  
  
  
const int N=100005;  
struct node{  
  ll min,max,sum,add;  
  void upd(int l,int r,ll x){  
    add+=x,min+=x,max+=x;  
    sum+=x*(r-l+1);  
  }  
}T[N<<2];  
  
inline void Pushup(int x,int l,int r) {  
  T[x].min=min(T[x<<1].min,T[x<<1|1].min)+T[x].add;  
  T[x].max=max(T[x<<1].max,T[x<<1|1].max)+T[x].add;  
  T[x].sum=T[x<<1].sum+T[x<<1|1].sum+T[x].add*(r-l+1);  
}  
  
inline void Sqrt(int x,int l,int r,int ql,int qr,ll tag) {  
  if(ql<=l && r<=qr) {  
    if (T[x].min==T[x].max  || T[x].max-T[x].min==(ll)sqrt(T[x].max+tag)-(ll)sqrt(T[x].min+tag)) {  
      ll ad=(ll)sqrt(T[x].min+tag)-T[x].min-tag;  
      T[x].upd(l,r,ad);  
      return;  
    }  
    Sqrt(x<<1,l,mid,ql,qr,tag+T[x].add),Sqrt(x<<1|1,mid+1,r,ql,qr,tag+T[x].add);  
    Pushup(x,l,r);  
    return;  
  }  
  if(ql<=mid) Sqrt(x<<1,l,mid,ql,qr,tag+T[x].add);  
  if(qr>mid) Sqrt(x<<1|1,mid+1,r,ql,qr,tag+T[x].add);  
  Pushup(x,l,r);  
}  
  
inline void Add(int x,int l,int r,int ql,int qr,ll tag) {  
  if(ql<=l&&r<=qr){  
    T[x].upd(l,r,tag);  
    return;  
  }  
  if(ql<=mid)  
    Add(x<<1,l,mid,ql,qr,tag);  
  if(qr>mid)  
    Add(x<<1|1,mid+1,r,ql,qr,tag);  
  Pushup(x,l,r);  
}  
  
inline ll Query(int x,int l,int r,int ql,int qr,ll add) {  
  ll ret=0;  
  if(ql<=l&&r<=qr)  
    return T[x].sum+add*(r-l+1);  
  if(ql<=mid)  
    ret+=Query(x<<1,l,mid,ql,qr,add+T[x].add);  
  if(qr>mid)  
    ret+=Query(x<<1|1,mid+1,r,ql,qr,add+T[x].add);  
  return ret;  
}  
  
int n;  
int Val[N];  
  
inline void Build(int x,int l,int r) {  
	T[x].min=T[x].max=T[x].sum=0;
  if(l==r){ T[x].min=T[x].max=T[x].sum=Val[l]; return; }  
  Build(x<<1,l,mid),Build(x<<1|1,mid+1,r);  
  Pushup(x,l,r);  
}  
  
int main(){ int PT;
	scanf("%d",&PT);
while(PT--)
{	
 	int Q; int order,l,r,t;  
 	scanf("%d%d",&n,&Q);
 	for (int i=1;i<=n;i++) scanf("%d",&Val[i]);  
 	Build(1,1,n);  
	while (Q--){  
		scanf("%d%d%d",&order,&l,&r);
	    if (order==1){  
			scanf("%d",&t);
	    	Add(1,1,n,l,r,t);  
	    }
		else if (order==2){  
	    	Sqrt(1,1,n,l,r,0);  
	    }
		else{  
	    	printf("%lld\n",Query(1,1,n,l,r,0));  
		}  
	}  
}
  return 0;  
}  
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<cstdio>  
#include<cstdlib>  
#include<algorithm>  
#include<cmath>  
#define mid ((l+r)>>1)  
using namespace std;  
typedef long long ll;  
  
  
const int N=100005;  
struct node{  
  ll min,max,sum,add;  
  void upd(int l,int r,ll x){  
    add+=x,min+=x,max+=x;  
    sum+=x*(r-l+1);  
  }  
}T[N<<2];  
  
inline void Pushup(int x,int l,int r) {  
  T[x].min=min(T[x<<1].min,T[x<<1|1].min)+T[x].add;  
  T[x].max=max(T[x<<1].max,T[x<<1|1].max)+T[x].add;  
  T[x].sum=T[x<<1].sum+T[x<<1|1].sum+T[x].add*(r-l+1);  
}  
  
inline void Sqrt(int x,int l,int r,int ql,int qr,ll tag) {  
  if(ql<=l && r<=qr) {  
    if (T[x].min==T[x].max  || T[x].max-T[x].min==(ll)sqrt(T[x].max+tag)-(ll)sqrt(T[x].min+tag)) {  
      ll ad=(ll)sqrt(T[x].min+tag)-T[x].min-tag;  
      T[x].upd(l,r,ad);  
      return;  
    }  
    Sqrt(x<<1,l,mid,ql,qr,tag+T[x].add),Sqrt(x<<1|1,mid+1,r,ql,qr,tag+T[x].add);  
    Pushup(x,l,r);  
    return;  
  }  
  if(ql<=mid) Sqrt(x<<1,l,mid,ql,qr,tag+T[x].add);  
  if(qr>mid) Sqrt(x<<1|1,mid+1,r,ql,qr,tag+T[x].add);  
  Pushup(x,l,r);  
}  
  
inline void Add(int x,int l,int r,int ql,int qr,ll tag) {  
  if(ql<=l&&r<=qr){  
    T[x].upd(l,r,tag);  
    return;  
  }  
  if(ql<=mid)  
    Add(x<<1,l,mid,ql,qr,tag);  
  if(qr>mid)  
    Add(x<<1|1,mid+1,r,ql,qr,tag);  
  Pushup(x,l,r);  
}  
  
inline ll Query(int x,int l,int r,int ql,int qr,ll add) {  
  ll ret=0;  
  if(ql<=l&&r<=qr)  
    return T[x].sum+add*(r-l+1);  
  if(ql<=mid)  
    ret+=Query(x<<1,l,mid,ql,qr,add+T[x].add);  
  if(qr>mid)  
    ret+=Query(x<<1|1,mid+1,r,ql,qr,add+T[x].add);  
  return ret;  
}  
  
int n;  
int Val[N];  
  
inline void Build(int x,int l,int r) {  
	T[x].min=T[x].max=T[x].sum=0;
  if(l==r){ T[x].min=T[x].max=T[x].sum=Val[l]; return; }  
  Build(x<<1,l,mid),Build(x<<1|1,mid+1,r);  
  Pushup(x,l,r);  
}  
  
int main(){ int PT;
	scanf("%d",&PT);
while(PT--)
{	
 	int Q; int order,l,r,t;  
 	scanf("%d%d",&n,&Q);
 	for (int i=1;i<=n;i++) scanf("%d",&Val[i]);  
 	Build(1,1,n);  
	while (Q--){  
		scanf("%d%d%d",&order,&l,&r);
	    if (order==1){  
			scanf("%d",&t);
	    	Add(1,1,n,l,r,t);  
	    }
		else if (order==2){  
	    	Sqrt(1,1,n,l,r,0);  
	    }
		else{  
	    	printf("%lld\n",Query(1,1,n,l,r,0));  
		}  
	}  
}
  return 0;  
}  
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
