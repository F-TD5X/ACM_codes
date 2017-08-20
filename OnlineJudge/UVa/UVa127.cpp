#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

char c,n;
vector<stack<pair<char,char> > > li;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("UVa127.in","r",stdin);
    //freopen("UVa127.out","w",stdout);
#endif
	stack<pair<char,char> >tmp;
	while(cin >>n && n!='#')
	{
		li.clear();
		while(!tmp.empty())
			tmp.pop();
		cin >> c;
		tmp.push(make_pair(c,n));
		li.push_back(tmp);
		for(int i=0;i<51;i++)
		{
			tmp.pop();
			cin >>n>>c;
			tmp.push(make_pair(c,n));
			li.push_back(tmp);
		}
		bool flag=1;
		bool ma=0;
		while(flag)
		{
			ma=0;
			for(int i=1;i<li.size();i++)
			{
				if(i>=3)
				{	
					if(li[i].top().fi == li[i-3].top().fi  || li[i].top().se == li[i-3].top().se)
					{
						ma=1;
						while(!li[i].empty())
						if(li[i].top().fi == li[i-3].top().fi  || li[i].top().se == li[i-3].top().se)
						{
							li[i-3].push(li[i].top());
							li[i].pop();
						}
						else
							break;
						if(li[i].empty())
						{
							li.erase(li.begin()+i);
							break;
						}
					}
				}
				else
				{
					if(li[i].top().fi == li[i-1].top().fi || li[i].top().se == li[i-1].top().se)
					{
						ma=1;
						while(!li[i].empty())
						if(li[i].top().fi == li[i-1].top().fi || li[i].top().se == li[i-1].top().se)
						{
							li[i-1].push(li[i].top());
							li[i].pop();
						}
						else
							break;
						if(li[i].empty())
						{
							li.erase(li.begin()+i);
							break;
						}
					}
				}
			}
			if(!ma)
				flag=0;
		}
		if(li.size()!=1)
		{
			cout << li.size()<<" piles remaining: ";
		}
		else
			cout <<1 <<" pile remaining:";
		for(auto a:li)
			cout << a.size() << " ";
		cout << endl;
	}
	return 0;
}
