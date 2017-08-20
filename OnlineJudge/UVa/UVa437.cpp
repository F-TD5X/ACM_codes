#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=30;
struct Node
{
	int x,y,z;
}a[maxn];

struct Node1
{
	int x,y,s;
}l[maxn<<2];

int idx[maxn];
int dp[maxn][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa437.in","r",stdin);
    //freopen("UVa437.out","w",stdout);
#endif
	while(cin >> n)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			cin >>a[i].x>>a[i].y>>a[i].z;

	}
	return 0;
}
