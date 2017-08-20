#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
multiset<int> e,o;
int a[maxn];
vector<int> ans;
int n,m;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> n >> m;
	for(int x,i=0;i<n;i++)
	{
		cin >> a[i];
		if(x%2)
			o.insert(x);
		else
			e.insert(x);
	}
	multiset<int>::iterator it1,it2;
	int cnt1=1,cnt2=2;
	for(int i=0;i<n;i++)
	{
		if(e.size()>o.size() && a[i]%2==1)
		{
			e.erase(e.lower_bound(a[i]));
			while(o.count(cnt2))
				cnt2+=2;
			a[i]=cnt2;
			o.insert(cnt2);
			cnt2+=2;
		}
		else if(e.size()<o.size() && a[i]%2==0)
		{
			o.erase(o.lower_bound(a[i]));
			a[i]=cnt1;
			e.insert(cnt1);
			cnt1+=2;
		}
		if(a[i]%2)
		{
			if(e.count(a[i])>1)
			{
				e.erase(e.lower_bound(a[i]));
				a[i]=cnt2;
				o.insert(cnt2);
				cnt2+=2;
			}
		}
		else
		{
			if(o.count(a[i])>1)
			{
				o.erase(o.lower_bound(a[i]));
				a[i]=cnt1;
				e.insert(cnt1);
				cnt1+=2;
			}
		}
	}
	if(e.size()!=o.size())
	{
		puts("NO");
		return 0;
	}
		int flag=0;
		for(auto k:e)
			if(e.count(k)>1)
			{
				puts("NO");
				return 0;
			}
		for(auto k:o)
			if(o.count(k)>1)
			{
				puts("NO");
				return 0;
			}
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		cout << endl;
	return 0;
}
