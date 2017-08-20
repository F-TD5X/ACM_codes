#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d;
double a;
const double PI =acos(-1);
double ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&d))
	{
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a);
			a=(a/360)*PI;
			ans+= (double)d*d*sin(a)*cos(a);
		}
		printf("%.3f\n",ans);
	}
	return 0;
}
