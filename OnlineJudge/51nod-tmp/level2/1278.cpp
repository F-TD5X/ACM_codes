#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	ll x,id;
}li[100100];

bool cmp(Node a,Node b)
{
	if(a.id=0&&a.x==b.x)
		return 1;
	return a.x<b.x;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1278.in","r",stdin);
    //freopen("1278.out","w",stdout);
#endif
	int n;
	int c,r;
	cin >> n;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin >> c >> r;
		li[cnt].id=0;
		li[cnt++].x=c-r;
		li[cnt].id=1;
		li[cnt++].x=c+r;
	}
	sort(li,li+cnt,cmp);
	int num=n,ans=0;
	for(int i=0;i<cnt;i++)
		if(li[i].id==0)
			num--;
		else
			ans+=num;
	cout << ans <<endl;
	return 0;
}
