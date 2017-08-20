#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ma,mi;
int nd,d,s;
const int INF=0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
#endif
	int T;
	mi=INF;
	ma=-INF;
	cin >>T;
	int sum=0;
	while(T--)
	{
		cin >>s>>d;
		if(d==1)
			mi=min(mi,sum);
		else
			ma=max(ma,sum);
		sum+=s;
	}
	if(ma>=mi)
	{
		puts("Impossible");return 0;}
	else
	{
		if(ma==-INF)
		{puts("Infinity");return 0;}
		if(mi==-INF)
		{printf("%d\n",1899-ma+sum);return 0;}
		int ans=max(1900-mi+sum,1899-ma+sum);
		cout << ans << endl;
	}
	return 0;
}
