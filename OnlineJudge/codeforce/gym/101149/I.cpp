#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+10;
vector<int> mp[maxn];
int n,m;
int cnt=0;
int vi[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
#endif
	fill(vi,vi+maxn,0);
	cin >> n >> m;
	int id=1;
	for(int x,y,i=0;i<m;i++)
	{
		cin >> x >> y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(n-mp[i].size()>n-mp[id].size())
			id=i;
	fill(vi,vi+maxn,1);
	for(auto a:mp[id])
		vi[a]=0;
	vi[id]=0;
	for(int i=1;i<=n;i++)
		cout << vi[i]<<" ";
	cout <<endl;
	return 0;
}
