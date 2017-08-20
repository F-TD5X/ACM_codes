#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
int c;
int d,e,f;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	while(~scanf("%d%d",&a,&b))
	{
		c=__gcd(a,b);
		d=a/c;
		e=b/c;
		f=d*d-4*e;
		if(f<0)
		{
			puts("No solution");
			continue;
		}
		int g=sqrt(f);
		if(g*g!=f)
		{
			puts("No solution");
			continue;
		}
		g=-g;
		int x=(g+d)/2*c;
		int y=a-x;
		printf("%d %d\n",x,y);
	}
	return 0;
}
