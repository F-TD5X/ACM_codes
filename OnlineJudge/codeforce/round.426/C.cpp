/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&n);while(n--){ll a,b;scanf("%I64d%I64d",&a,&b);ll c=cbrt(1.0*a*b);ll x=a/c,y=b/c;puts((x*x*y==a)&&(y*y*x==b)?"YES":"NO");}

	return 0;
}
