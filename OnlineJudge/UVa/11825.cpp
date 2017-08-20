<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20;
int kase,n;
int a[maxn],dp[(1<<maxn)+100],uni[(1<<maxn)+100];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("11825.in","r",stdin);
    //freopen("11825.out","w",stdout);
#endif
	while(~scanf("%d",&n) && n) {
		for(int m,i=0;i<n;i++){
			scanf("%d",&m);
			a[i]=1<<i;
			for(int x,j=0;j<m;j++){
				scanf("%d",&x);
				a[i]|=(1<<x);
			}
		}
		for(int i=0;i<(1<<n);i++){
			uni[i]=0;
			for(int j=0;j<n;j++){
				if(i & (1<<j)) uni[i]|=a[j];
			}
		}
		dp[0]=0;
		int ALL=(1<<n)-1;
		for(int i=1;i<(1<<n);i++){
			dp[i]=0;
			for(int j=i;j;j=(j-1)&i){
				if(uni[j]==ALL) dp[i]=max(dp[i],dp[i^j]+1);
			}
		}
		printf("Case %d: %d\n",++kase,dp[ALL]);

	}

	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20;
int kase,n;
int a[maxn],dp[(1<<maxn)+100],uni[(1<<maxn)+100];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("11825.in","r",stdin);
    //freopen("11825.out","w",stdout);
#endif
	while(~scanf("%d",&n) && n) {
		for(int m,i=0;i<n;i++){
			scanf("%d",&m);
			a[i]=1<<i;
			for(int x,j=0;j<m;j++){
				scanf("%d",&x);
				a[i]|=(1<<x);
			}
		}
		for(int i=0;i<(1<<n);i++){
			uni[i]=0;
			for(int j=0;j<n;j++){
				if(i & (1<<j)) uni[i]|=a[j];
			}
		}
		dp[0]=0;
		int ALL=(1<<n)-1;
		for(int i=1;i<(1<<n);i++){
			dp[i]=0;
			for(int j=i;j;j=(j-1)&i){
				if(uni[j]==ALL) dp[i]=max(dp[i],dp[i^j]+1);
			}
		}
		printf("Case %d: %d\n",++kase,dp[ALL]);

	}

	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
