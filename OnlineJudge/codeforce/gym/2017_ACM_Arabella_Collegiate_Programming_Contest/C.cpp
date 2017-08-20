#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
int n;
const int maxn=1e5+100;
ll arr[maxn];
ll sum;
ll tg;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%I64d",&T);
	while(T--){
		sum=0;
		tg=0;
		scanf("%I64d",&n);
		for(int i=0;i<n;i++){
			scanf("%I64d",arr+i);
			sum+=arr[i];
			tg=__gcd(tg,arr[i]);
		}
		printf("%I64d %I64d\n",sum,tg);
	}

	return 0;
}
