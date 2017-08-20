#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int a,b,c;
	cin >> a >> b >> c;
	int t=max(a,max(b,c));
	if(a+b+c-t==t)
		puts("Yes");
	else
		puts("No");
	return 0;
}
