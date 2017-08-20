/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003data.in","r",stdin);
    freopen("1003.in","w",stdout);
#endif
	srand(time(0));
	int T=1;
	cout << T<<endl;
	ll l,r,k;
	while(T--){
		l=rand()%ll(1e12);
		r=rand()%ll(1e12);
		k=rand()%ll(1e7);
		if(max(r,l)-min(r,l)>1e6)
		{
			T++;
			continue;
		}
		cout << min(l,r) <<" " << max(l,r) <<" " << k<<endl;
	}
	return 0;
}
