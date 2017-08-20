#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("250.in","r",stdin);
    //freopen("250.out","w",stdout);
#endif
	string s;
	cin >> s;
	vector<int> mp[10];
	for(int i=0;i<s.size();i++)
		mp[s[i]-'0'].push_back(i);
	bool flag=1;
	for(int i=0;i<=9;i++)
	{
		int pre;
		if(mp[i].size()%2)
		{
			cout <<"Not interesting"<<endl;
			return 0;
		}
		else if(mp[i].size()==0)
		{
			continue;
		}
		pre=mp[i][0];
		for(int j=1;j<mp[i].size();j++)
		{
			if(mp[i][j]-pre-1>i)
			{
				cout <<"Not interesting"<<endl;
				return 0;
			}
			pre=mp[i][j];
		}
	}
	cout << "Interesting" << endl;
	return 0;
}
