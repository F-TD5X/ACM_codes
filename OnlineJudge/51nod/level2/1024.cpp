/*Author: NoZuoNoDieWhyITry*/
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
	int n,m,a,b;
	while(cin >> m >> n >>a >> b){
		s.clear();
		for(int i=a; i<a+n;i++){
			for(int j=b;j<b+m;j++){
				s.insert(1.0*j*log2(1.0*i));
			}
		}
		cout <<s.size()<<endl;
	}
	return 0;
}
