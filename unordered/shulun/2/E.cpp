#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+2,N=maxn;
int d[maxn],c[maxn];
int l,r;
void init()
{
	for(int i=2;i<maxn;++i)
		if(!d[i])
			for(int x=i;x<maxn;x+=i)
				d[x]=i;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	init();
	int n,x;
	int p;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		while(x>1)
			for(c[p=d[x]]++;x%p==0;x/=p);
	}
	for(int i=2;i<maxn;i++)
		c[i]+=c[i-1];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",c[r<N-1?r:N-1]-c[l<N?l-1:N-1]);
	}
	return 0;
}
