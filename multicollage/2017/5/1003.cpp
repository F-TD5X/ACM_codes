/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=(2e5+10)*4;
int n,m;
int a[maxn],aa[maxn],pre[maxn];

void add(int i,int x){
	while(i<=n){
		pre[i]+=x;
		i+=i&-i;
	}
}

int read(int i){
	int ret=0;
	while(i){
		ret+=pre[i];
		i-=i&-i;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m)){
		for(int t,i=1;i<=n;i++){
			scanf("%d",&t);
			add(i,t);
			a[i]=t;
			aa[i]=t;
		}
		int op,l,r,k;
		while(m--){
			scanf("%d%d%d",&op,&l,&r);
			if(op==1){
				printf("%d\n",read(r)-read(l-1));
			}
			else if(op == 2){
				scanf("%d",&k);
				for(int i=l;i<=r;i++){
					add(i,a[i-k]-a[i]);
					a[i]=a[i-k];
				}
			}
			else if(op==3){
				for(int i=l;i<=r;i++){
					add(i,aa[i]-a[i]);
					a[i]=aa[i];
				}
			}
		}
	}

	return 0;
}
