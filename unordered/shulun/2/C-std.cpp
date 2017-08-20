#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("C-std.in","r",stdin);
    //freopen("C-std.out","w",stdout);
#endif
	int x,k,c,m=1;
	scanf("%d%d",&x,&k);
		while(x--)
		{
			scanf("%d",&c);
			c=__gcd(c,k);
			m=lcm(m,c);
		}
		puts(m-k?"No":"Yes");
	return 0;
}
