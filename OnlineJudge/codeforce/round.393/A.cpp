#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int n,m;
	cin >> n >> m;
	m=8-m;
	cout << (1+(a[n-1]-m+6)/7)<<endl;
	return 0;
}
