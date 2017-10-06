/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
ll pre[maxn];
ll M[maxn];
int n,m;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("514.in","r",stdin);
    //freopen("514.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m)){
		memset(M,-0x3f,sizeof M);
		for(int i=1;i<=n;i++) {scanf("%d",a+i); pre[i]=pre[i-1]+a[i];}
		for(int i=n;i>=0;i--){
			for(int j=0;j+i<=n;j++)
				M[i] = max(M[i],pre[i+j]-pre[j]);
			M[i]=max(M[i],M[i+1]);
		}
		for(int x,i=0;i<m;i++){
			scanf("%d",&x);
			printf("%lld\n",M[x]);
		}

	}
	return 0;
}
