/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=1e5+100;
set<int> s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> n >>m;
	if(n==m){
		printf("*");
		return 0;
	}
	for(int t,i=1;i<=m;i++){
		cin>>t;
		s.insert(t);
	}
	for(int i=1;i<=n;i++){
		if(!s.count(i))
			cout <<i <<" ";
	}

	return 0;
}
