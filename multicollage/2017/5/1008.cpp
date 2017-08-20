/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
int T;
int n,m;
ll C[51][51];
int ans[maxn],id;
map<ll,ll> mp;

void init()
{
	C[1][0]=C[1][1]=1;
	for(int i=2;i<=50;i++){
		C[i][0]=1;
		for(int j=1;j<=50;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
#endif
	init();
	scanf("%d",&T);
	while(T--){
		id=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=m;i++)
			scanf("%lld",nm+i);
		for(int i=1;i<m;i++){
			for(auto num:mp){
				for(int j=2;j*i<=m && j<nm[i];j++)
					nm[j*i+num.first]-=C[nm[i]][j];
			}
			while(nm[i]--)
				ans[id++]=i;
		}
	}
	return 0;
}
