/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=111;
int T;
int n;
int ans;
int a[8];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		while(n--){
			bool flag=1;
			int sum=0;
			for(int j=0;j<7;j++)
				scanf("%d",a+j);
			a[0]-=a[3]+a[5]-a[6];
			a[1]-=a[3]+a[4]-a[6];
			a[2]-=a[4]+a[5]-a[6];
			a[3]-=a[6];
			a[4]-=a[6];
			a[5]-=a[6];
			for(int i=0;i<7;i++){
				sum+=a[i];
				if(a[i]<0)
					flag=0;
			}
			if(flag)
				ans=max(ans,sum);
		}
		printf("%d\n",ans);
	}

	return 0;
}
