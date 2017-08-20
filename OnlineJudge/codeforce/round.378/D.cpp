#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<int,int>,pair<int,int>> old;
int be;
vector<int> sol;

void OK(int a,int b,int c,int i)
{
	if(old.count({a,b})==0)
		return;
	auto p=old[{a,b}];
	int now=min(min(a,b),p.first+c);
	if(be<now)
	{
		be=now;
		sol={p.second,i};
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	int n;
	cin >>n;
	int a,c,b;
	for(int i=0;i<n;i++)
	{
		cin >> a>>b>>c;
		if(a>b)
			swap(a,b);
		if(a>c)
			swap(a,c);
		if(b>c)
			swap(b,c);
		if(be<a)
		{
			be=a;
			sol={i};
		}
		OK(a,b,c,i);
		OK(a,c,b,i);
		OK(b,c,a,i);
		old[{a,b}]=max(old[{a,b}],{c,i});
		old[{b,c}]=max(old[{b,c}],{a,i});
		old[{a,c}]=max(old[{a,c}],{b,i});
	}
	cout << sol.size()<<endl;
	for(auto x:sol)
		cout <<x+1<<" ";
	cout <<endl;
	return 0;
}
