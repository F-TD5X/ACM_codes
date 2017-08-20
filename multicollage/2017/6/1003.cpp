/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+10;
int T,n;
int a[maxn];
int tr[maxn<<2];

void b(int st,int l,int r){
	if(l==r){
		scanf("%d",a+l);
		tr[st]=a[l];
		return;
	}
	int m=(l+r)>>1;
	b(st<<1,l,m);
	b(st<<1|1,m+1,r);
	tr[st]=max(tr[st<<1],tr[st<<1|1]);
}
int ans=0;
int L,R;
void q(int st,int l,int r){
	if(L<=l && r<=R){
		ans=max(ans,tr[st]);
	   	return;
	}
	int m=(l+r)>>1;
	if(L<=m)q(st<<1,l,m);
	if(R>m)q(st<<1|1,m+1,r);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		b(1,1,n);
		for(int p=a[1],i=2;i<=n;i++){
			ans=p;
			for(int j=i;j<n;j+=i){
				L=j+1,R=j+i-1;
				q(1,1,n);
			}
			printf("%d",ans);
			if(i!=n)
				printf(" ");
			p=max(a[i],p);
		}
		puts("");
	}
	return 0;
}
