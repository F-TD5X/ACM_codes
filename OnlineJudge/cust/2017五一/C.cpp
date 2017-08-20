#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=1e6+100;
int a[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		printf("%d\n",a[(n+1)/2]);
	}
	return 0;
}
