#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
long double n,p;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1065-Just_for_Fun.in","r",stdin);
    //freopen("1065-Just_for_Fun.out","w",stdout);
#endif
	cin >>T;
	while(T--)
	{
		cin >>n>>p;
		if(n==1||p==0)
			puts("Y");
		else
			puts("N");
	}
	return 0;
}
