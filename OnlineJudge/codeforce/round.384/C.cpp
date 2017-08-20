#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll x,y,z;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n;
	if(n==1)
		cout << -1 <<endl;
	else
		cout << n <<" " << n+1<<" " << n*(n+1)<<endl; 
	return 0;
}
