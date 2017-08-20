/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1067.in","r",stdin);
    //freopen("1067.out","w",stdout);
#endif
	cin >> t;
	while(t--){
		cin >> n;
		if(n%7==2 || n%7==0)
			cout <<"B"<<endl;
		else
			cout <<"A"<<endl;
	}
	return 0;
}
