#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double n;
int m;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("6.in","r",stdin);
    //freopen("6.out","w",stdout);
#endif
	double ans;
	while(cin >>n>>m)
	{
		ans=0;
		for(int i=0;i<m;i++)
		{
			ans+=n;
			n=sqrt(n);
		
		}
		printf("%.2f\n",ans);
	}

	return 0;
}
