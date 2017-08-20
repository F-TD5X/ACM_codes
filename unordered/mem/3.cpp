#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("3.in","r",stdin);
    //freopen("3.out","w",stdout);
#endif
	double r;
	while(cin >> r)
	{
		printf("%.3f\n",acos(-1)*r*r*r*4/3);
	}
	return 0;
}
