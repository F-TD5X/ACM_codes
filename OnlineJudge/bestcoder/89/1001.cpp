#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
int T;
int ans;
set<int> y,r,x;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
#endif
	cin >> T;
	string s;
	while(T--)
	{
		cin >>s;
		ans=0;
		y.clear();x.clear();r.clear();
		for(int i=0;i<s.size();i++)
			if(s[i]=='r')
				r.insert(i+1);
			else if(s[i]=='x')
				x.insert(i+1);
			else if(s[i]=='y')
				y.insert(i+1);
		for(auto a:y)
			for(auto b:r)
				if(x.count(int(1.0*b*(b/a))) && b%a==0)
					ans++;
		cout << ans <<endl;
	}
	return 0;
}
