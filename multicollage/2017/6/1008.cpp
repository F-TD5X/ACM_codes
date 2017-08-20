/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=5e3+10;
int T,m;
int ans;
char s[maxn];
int len=0;
int pre[maxn];

inline int cac(int l,int r){
	if(l<0 || r>=len)
		return 0;
	int ret=0,st=r-1;
	pre[st]=0;
	while(0<= l && r<len){
		pre[r]=pre[r-1]+abs(s[l]-s[r]);
		while(st < r && pre[r]-pre[st]>m) 
			st++;
		ret=max(ret,r-st);
		l--,r++;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%s",&m,s);
		len=strlen(s);
		for(int i=0;i<len;i++){
			for(int j=1;j<=3;j++)
				ans=max(ans,cac(i,i+j));
		}
		printf("%d\n",ans);
	}
	return 0;
}
