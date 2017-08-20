#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp(x,y) make_pair(x,y)

const int maxn=2e5+10;
struct Node
{
	int l,r;
	bool operator<(Node a)
	{
		if(a.l == l)
			return r>a.r;
		return l>a.l;
	}
}ma[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	int n,ans=0;
	cin >> n;
	int ml=0,mr=0;
	for(int x,y,i=0;i<n;i++)
	{
		cin >> x>> y;
		ma[i]={x,y};
		if(x>=ml)
		{
			ml=max(x,ml);
			mr=max(y,mr);
		}
	}
	sort(ma,ma+n);
	for(int i=0;i<n;i++)
	{
		if(ma[i].r>=ml)
			ans++;
	}
	cout <<ans<<endl;
	return 0;
}
