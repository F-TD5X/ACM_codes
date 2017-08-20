#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("4.in","r",stdin);
    //freopen("4.out","w",stdout);
#endif
	double x1,x2,y1,y2;
	while(cin >> x1 >> x2 >> y1 >> y2)
	{
		printf("%.2f\n",sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	}
	return 0;
}
