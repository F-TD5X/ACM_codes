#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
double r,R,ans;
const double pi=acos(-1);
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	int T;
	cin >> T;
	while(T--)
	{
		cin >> r >> R;
		printf("Case #%d:%d\n",pi*(R*R-r*r));
	}
	return 0;
}
