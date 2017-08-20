/*	temple of Snakes(Codechef)*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n;
const int maxn=1e5+100;
ll ma,arr[maxn],ans,l[maxn],r[maxn],all;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		ans=all=ma=0;
		scanf("%d",&n);
		r[n+1]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",arr+i);
			all+=arr[i];
			l[i]=min(l[i-1]+1,arr[i]);
		}
		for(int i=n;i;i--){
			r[i]=min(r[i+1]+1,arr[i]);
			ma=max(ma,min(l[i],r[i]));
		}
		printf("%lld\n",all-ma*ma);
	}
	return 0;
}
