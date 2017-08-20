#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int sz[maxn],p[maxn];
double dp[maxn];

int main()
{
	int n;
	cin >> n;
	for(int i =2;i<=n;i++)	//输入
		cin >> p[i];
	for(int i =1;i<=n;i++)	//初始化
		sz[i]=1；
	for(int i =n;i>=2;i--)
		sz[p[i]]+=sz[i];
	dp[1]=1;
	for(int i =2;i<=n;i++)
		dp[i]=dp[p[i]]+1+(sz[p[i]]-sz[i]-1)/2.0;
	for(int i =1;i<=n;i++)
		cout << dp[i]<<endl;
	return 0;
}