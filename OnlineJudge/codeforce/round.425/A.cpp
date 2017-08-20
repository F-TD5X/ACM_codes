#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n >> k;
	if((n/k)%2==1)
		cout << "YES"<<endl;
	else
		cout <<"NO"<<endl;
	return 0;
}
