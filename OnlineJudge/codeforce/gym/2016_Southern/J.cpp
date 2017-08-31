#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Node
{
	int r,v;
}a[111],b[111],c[111];
int ans,ti;


int cmp(Node a ,Node b)
{
	return a.r<b.r;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("J.in","r",stdin);
    //freopen("J.out","w",stdout);
#endif
	cin >> n;
	ll sum=0,sum_v=0;
	for(int i=0;i<n;i++)
		cin >> a[i].r;
	for(int i=0;i<n;i++)
		cin >> a[i].v;
	memcpy(b,a,sizeof(a));
	sort(a,a+n,cmp);
	for(int )
	return 0;
}
