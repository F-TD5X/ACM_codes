/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int f[maxn];
int n;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("6217.in","r",stdin);
    //freopen("6217.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int x,y,i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		for(int j =n;j>=x;--j){
			f[j]=max(f[j],f[j-x]+y);
		}
	}
	printf("%d\n",f[n]);


	return 0;
}
