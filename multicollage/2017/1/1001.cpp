#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double n;
int ans=0;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
#endif
	int kase=1;
	while(~scanf("%lf",&n)){
		ans=n*log(2)/log(10);
		printf("Case #%d: %d\n",kase++,ans);
	}

	return 0;
}
