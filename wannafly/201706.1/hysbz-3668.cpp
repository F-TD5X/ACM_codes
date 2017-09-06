/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unsigned int n,m,sum,ans;
const int maxn=1e5+10;
char s[maxn][4],a[maxn];
int x;

bool cac(int p,int pos){
	for(int i=0;i<n;i++){
		int c=a[i]&(1<<pos);
		if(c)
			c=1;
		if(s[i][0]=='A')
			p&=c;
		else if(s[i][0]=='O')
			p|=c;
		else if(s[i][0]=='X')
			p^=c;
	}
	return p;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("hysbz-3668.in","r",stdin);
    //freopen("hysbz-3668.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m)){
		sum=ans=0;
		for(int i=0;i<3;i++)
			scanf("%s%d",s[i],a+i);
		for(int i=31;i>=0;i--){
			if(cac(0,i)){
				ans+=(1<<i);
				continue;
			}else if(cac(1,i)){
				int c=sum+(1<<i);
				if(c<=m){
					sum=c;
					ans+=(1<<i);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
