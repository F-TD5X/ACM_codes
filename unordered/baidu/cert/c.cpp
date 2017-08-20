#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+100;

ll a[maxn],b[maxn],k[maxn],p[maxn];
ll ans,n,m;
ll f[11][2111];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
#endif
	while(~scanf("%I64d%I64d",&n,&m)){
		memset(f,0x3f,sizeof(f));
		ans=0;
		ll maxhp=0;
		for(int i=0;i<n;i++){
			scanf("%I64d%I64d",a+i,b+i);
			maxhp=max(maxhp,a[i]);
		}
		for(int i=1;i<=m;i++)
			scanf("%I64d%I64d",k+i,p+i);
		for(int i=0;i<=10;i++)
			f[i][0]=0;
		for(int t=10;t>=0;t--){
			for(int i=1;i<=m;i++){
				if(p[i]<=t)
					continue;
					for(int j=1;j<p[i]-t;j++)
						f[t][j]=min(f[t][j],k[i]);
					for(int j=p[i]-t;j<=maxhp;j++)
						f[t][j]=min(f[t][j],f[t][j-p[i]+t]+k[i]);
			}
		}
		bool flag=0;
		for(int i=0;i<n;i++){
			if(f[b[i]][a[i]] == 0x3f3f3f3f3f3f3f3f)
				flag=1;
			ans+=f[b[i]][a[i]];
		}

		if(flag)
			puts("-1");
		else
			printf("%I64d\n",ans);
	}
	return 0;
}
