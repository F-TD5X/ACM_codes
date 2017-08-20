/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+10;
int n,m;
int a[maxn],b[maxn];
ll num1[maxn],num2[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1006.in","r",stdin);
    //freopen("1006.out","w",stdout);
#endif
	int kase=1;
	while(~scanf("%d%d",&n,&m)){
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<m;i++)
			scanf("%d",b+i);
		int cycle=0;
		for(ll tot=0,i=0;i<n;i++,tot=0){
			int k=i;
			while(a[k]!=-1){
				tot++;
				int t=k;
				k=a[k];
				a[t]=-1;
			}
			if(tot)
				num1[++cycle]=tot;
		}
		for(ll tot=0,i=0;i<m;i++,tot=0){
			int k=i;
			while(b[k]!=-1){
				tot++;
				int t=k;
				k=b[k];
				b[t]=-1;
			}
			if(tot)
				num2[tot]++;
		}
		ll ans=1;
		for(ll i=1;i<=cycle;i++){
			ll ans1=0;
			for(int j=1;j*j<=num1[i];j++){
				if(num1[i]%j==0)
					if(j*j==num1[i])
						ans1+=num2[j]*j;
					else
						ans1+=num2[j]*j+num2[num1[j]/j]*num1[j]/j;
			}
			ans=ans*ans1%mod;
		}
		printf("Case #%d: %lld\n",kase++,ans);
	}
	return 0;
}
