#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<double> s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1024.in","r",stdin);
    //freopen("1024.out","w",stdout);
#endif
	int a,b,m,n;
	s.clear();
	cin >>m>>n>> a >>b;
	for(int i=a;i<a+n;i++)
		for(int j=b;j<b+m;j++)
			s.insert((double)j*log2((double)i));
	cout << s.size()<<endl;
	return 0;
}
