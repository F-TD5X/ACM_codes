<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1111;
set<string> name,n2;
vector<string> ans;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n;
	string str,str1;
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		cin >> str>>str1;
		
		if(!name.count(str.substr(0,2)+str1[0]))
		{
			ans.push_back(str.substr(0,2)+str1[0]);
			name.insert(str.substr(0,2)+str1[0]);
			n2.insert(str.substr(0,3));
		}
		else if(!name.count(str.substr(0,3)) && !n2.count(str.substr(0,3)))
		{
			ans.push_back(str.substr(0,3));
			name.insert(str.substr(0,3));
		}
		else
		{
			flag=1;break;
		}
	}
	if(flag)
		puts("NO");
	else
	{
		puts("YES");
		for(auto a:ans)
			cout << a << endl;
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1111;
set<string> name,n2;
vector<string> ans;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n;
	string str,str1;
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		cin >> str>>str1;
		
		if(!name.count(str.substr(0,2)+str1[0]))
		{
			ans.push_back(str.substr(0,2)+str1[0]);
			name.insert(str.substr(0,2)+str1[0]);
			n2.insert(str.substr(0,3));
		}
		else if(!name.count(str.substr(0,3)) && !n2.count(str.substr(0,3)))
		{
			ans.push_back(str.substr(0,3));
			name.insert(str.substr(0,3));
		}
		else
		{
			flag=1;break;
		}
	}
	if(flag)
		puts("NO");
	else
	{
		puts("YES");
		for(auto a:ans)
			cout << a << endl;
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
