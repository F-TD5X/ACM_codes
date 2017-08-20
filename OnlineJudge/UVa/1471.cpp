#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int maxn=2e5+10;
int a[maxn];
int f[maxn],g[maxn];

struct Node
{
	int ele,l;
	Node(int ele,int l):ele(ele),l(l){}
	bool operator< (const Node &tmp) const
	{
		return ele<tmp.ele;
	}
};

set<Node> s;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1471.in","r",stdin);
    //freopen("1471.out","w",stdout);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int ans=0;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
			cin >>a[i];
		g[0]=1;
		for(int i=1;i<n;i++)
			if(a[i]>a[i-1])
				g[i]=g[i-1]+1;
			else
				g[i]=1;
		f[n-1]=1;
		for(int i=n-2;i>=0;i--)
			if(a[i]<a[i+1])
				f[i]=f[i+1]+1;
			else
				f[i]=1;
		s.insert(Node(a[0],g[0]));
		set<Node>::iterator it;
		bool keep;
		for(int i=1;i<n;i++)
		{
			Node t(a[i],g[i]);
			it=s.lower_bound(t);
			keep=1;
			if(it!=s.begin())
			{
				Node tt=*(--it);
				ans=max(ans,f[i]+tt.l);
				if(t.l<=tt.l)
					keep=0;
			}
			if(keep)
			{
				s.erase(t);
				s.insert(t);
				it=s.find(t);
				it++;
				while(it!=s.end() && it->ele>t.ele && it->l<=t.l)
					s.erase(it++);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
