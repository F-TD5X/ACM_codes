#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	int l,r;
	Node(int l=0,int r=0):l(l),r(r){}
};
vector<Node> lines;
bool cmp(Node a,Node b)
{
	if(a.r==b.r)
		return a.l>b.l;
	return a.r<b.r;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1133.in","r",stdin);
    //freopen("1133.out","w",stdout);
#endif
	int x,y,n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		lines.push_back(Node(x,y));
	}
	sort(lines.begin(),lines.end(),cmp);
	int l,r,ans=0;
	l=r=-2e9;
	for(auto a:lines)
		if(a.l>=r)
		{
			r=a.r;
			ans++;
		}
	cout <<ans <<endl;
	return 0;
}
