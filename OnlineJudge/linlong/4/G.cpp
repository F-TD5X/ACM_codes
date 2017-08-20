#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<double> s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
	int t;
	cin >> t;
	int x0,y0,x,y,n;
	while(t--)
	{
		s.clear();
		cin >> x0 >> y0>>n;
		while(n--)
		{
			cin >> x>>y;
			s.insert(1.0*(x-x0)/(y-y0));
		}
		cout << s.size()<<endl;
	}
	return 0;
}
