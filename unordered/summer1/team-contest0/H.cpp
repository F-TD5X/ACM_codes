#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e6+10;
int n,m;
int T;
ll dp[N<<1];
int v[N];
int t[N];

int main()
{
    scanf("%d",&n);
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		scanf("%d%d",&v[x],&t[x]);
	}
	for(int i=N-1;i>=0;i--)
	{
		dp[i]=dp[i+1];
		if(v[i])
			dp[i]=max(dp[i],v[i]+dp[i+t[i]]);
	}
	printf("%I64d\n",dp[0]);
    return 0;
}
