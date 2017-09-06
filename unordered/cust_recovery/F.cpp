/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	while(~scanf("%d + %d = %d",&a,&b,&c)){
		if(a+b ==c)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
