#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double a,b;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("J.in","r",stdin);
    //freopen("J.out","w",stdout);
#endif
	cin >> n;
	int kase=1;
	double ans;
	while(n--)
	{
		ans=0.01;
		cin >> a >> b;

		if(b==0.01 && a!=0.02) ans=0.02;
		if(b==0.1 && a!=0.2) ans=0.11;
		if(b==1 && a!=2) ans=1.01;
		if(b==10 && a!=20) ans=10.01;

		printf("Case #%d: %.2f\n",kase++,ans);
	}

	return 0;
}
