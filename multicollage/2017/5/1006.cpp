/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6+10;

int T,n,m;
int ans;
int cnt[maxn][3];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1006.in","r",stdin);
    //freopen("1006.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			cnt[i][0]=cnt[i][1]=0;cnt[i][2]=n-1;
		}
		if(m<n-1){
			cnt[1][0]=m;cnt[1][2]-=m;
			for(int i=2;i<=m+1;i++){
				cnt[i][0]=1;cnt[i][1]=m-1;cnt[i][2]-=m;
			}
		}
		else{
			int t=0;
			for(int i=1;i<=n;i++){
				if(m>=n-t){
					cnt[i][0]=n-1;cnt[i][1]=cnt[i][2]=0;
					m-=n-i-t;
					t++;
				}
				else if(t){
					cnt[i][0]=t+m;
					for(int j=i+1;j<=n && m ;j++,m--){
						cnt[i][0]+=1;cnt[i][2]-=1;
					}
					cnt[i][1]=n-1-cnt[i][0];
					cnt[i][2]=0;
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=cnt[i][0]+cnt[i][1]*2+cnt[i][2]*n;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
