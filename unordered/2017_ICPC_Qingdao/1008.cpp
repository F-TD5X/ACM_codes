/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int> mp;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
#endif
	mp["rat"]=0;
	mp["ox"]=1;
	mp["tiger"]=2;
	mp["rabbit"]=3;
	mp["dragon"]=4;
	mp["snake"]=5;
	mp["horse"]=6;
	mp["sheep"]=7;
	mp["monkey"]=8;
	mp["rooster"]=9;
	mp["dog"]=10;
	mp["pig"]=11;
	int T;
	cin >> T;
	string s1,s2;
	
	while(T--){
		cin >> s1 >> s2;
		int t=mp[s2]-mp[s1]+12;
		t%=12;
		if(t==0)
			cout << 12 << endl;
		else
			cout << t << endl;
	}
	return 0;
}
