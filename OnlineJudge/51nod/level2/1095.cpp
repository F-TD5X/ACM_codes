/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
map<string,int> mp1,mp2;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1095.in","r",stdin);
    //freopen("1095.out","w",stdout);
#endif
	int T,Q;
	cin >> T;
	while(T--){
		cin>>s;
		mp1[s]++;
		sort(s.begin(),s.end());
		mp2[s]++;
	}
	cin >>Q;
	while(Q--){
		cin >> s;
		int t=mp1[s];
		sort(s.begin(),s.end());
		cout << mp2[s]-t<<endl;
	}
	return 0;
}
