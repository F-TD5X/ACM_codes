#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
map<string,int> mp;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	mp["monday"]=0;
	mp["tuesday"]=1;
	mp["wednesday"]=2;
	mp["thursday"]=3;
	mp["friday"]=4;
	mp["saturday"]=5;
	mp["sunday"]=6;
	cin >>s1>>s2;
	if((mp[s1]+28)%7==mp[s2] || (mp[s1]+30)%7==mp[s2] || (mp[s1]+31)%7==mp[s2])
		cout <<"YES"<<endl;
	else
		cout <<"NO"<<endl;
	return 0;
}
