#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+100;
typedef long long ll;
ll a[maxn];
void init()  
{
	ll i,j,t,ok;
	ll ans=0;
	for(i=1;i<=maxn;i++) {
		if(i%7!=0) {
		    t=i;ok=1;
			while(t) {
				if(t%10==7) {
					ok=0;break;
				}
				t=t/10;
			}
			if(ok) ans+=i*i;
		}
		a[i]=ans;	
	}
}

int main()
{
	int i,j,t,n;
	init();
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		printf("%I64d\n",a[n]);
	}
	return 0;
}


