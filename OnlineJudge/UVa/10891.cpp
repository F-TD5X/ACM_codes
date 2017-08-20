<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111;
int n,a[maxn],pre[maxn],dp[maxn][maxn],vis[maxn][maxn];

int solve(int l,int r)
{
	if(vis[l][r]) return dp[l][r];
	vis[l][r]=1;
	int m=0;
	for(int i=l+1;i<=r;i++) 
		m=min(m,solve(i,r));
	for(int i=l;i<r;i++)
		m=min(m,solve(l,i));
	dp[l][r]=pre[r]-pre[l-1] -m;
	return dp[l][r];
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("10891.in","r",stdin);
    //freopen("10891.out","w",stdout);
#endif
	while(~scanf("%d",&n) && n){
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			pre[i]=pre[i-1]+a[i];
		}
		int ans=solve(1,n);
		printf("%d\n",2*ans-pre[n]);
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111;
int n,a[maxn],pre[maxn],dp[maxn][maxn],vis[maxn][maxn];

int solve(int l,int r)
{
	if(vis[l][r]) return dp[l][r];
	vis[l][r]=1;
	int m=0;
	for(int i=l+1;i<=r;i++) 
		m=min(m,solve(i,r));
	for(int i=l;i<r;i++)
		m=min(m,solve(l,i));
	dp[l][r]=pre[r]-pre[l-1] -m;
	return dp[l][r];
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("10891.in","r",stdin);
    //freopen("10891.out","w",stdout);
#endif
	while(~scanf("%d",&n) && n){
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			pre[i]=pre[i-1]+a[i];
		}
		int ans=solve(1,n);
		printf("%d\n",2*ans-pre[n]);
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
