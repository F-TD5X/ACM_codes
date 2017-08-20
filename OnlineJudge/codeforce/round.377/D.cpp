#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
const int maxn=1e5+10;
int d[maxn],t[maxn];
vector<int> order;
int tmp[maxn];
bool f[maxn];
int e[maxn];

bool check(int n)
{
	memset(e,0,sizeof(e));
	memset(f,0,sizeof(f));
	order.clear();
	for(int i=n;i>=1;i--)
		if( d[i]&&!f[d[i]])
			f[d[i]]=1, order.push_back(d[i]), e[i]=d[i];
	for(int i=1;i<=m;i++)
		if(!f[i])return 0;
	reverse(order.begin(),order.end());
	memcpy(tmp,t,sizeof(t));
	int j=0;
	for(int i=1;i<=n;i++)
	{
		if(e[i])
		{
			if(tmp[e[i]])
				return 0;
			continue;
		}
		tmp[order[j]]--;
		if(!tmp[order[j]])
			j++;
		if(j==m)
			return 1;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> d[i];
	for(int i=1;i<=m;i++)
		cin >> t[i];
	int l=1,r=n;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(check(m))
			r=m-1;
		else
			l=m+1;
	}
	cout << (l>n?-1:l)<<endl;
	return 0;
}
