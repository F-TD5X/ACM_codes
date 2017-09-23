/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n >>m;
	if(m == 0|| m == n){
		cout << 0 <<" " << 0 << endl;
	}
	else{
		cout <<  1<<" " << min(n-m,2*m)<<endl;
	}

	return 0;
}
