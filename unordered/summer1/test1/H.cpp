#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e6+10;
int n,dp[1111][1121];
int arr[1111];

int dfs(int l,int r)
{
    if(l>r)
        return 0;
    if(l==r)
        return arr[l];
    if(dp[l][r]!=-1)
        return dp[l][r];
    int tl=0,tr=0;
    if(arr[r]>arr[l+1])
        tl=dfs(l+1,r-1)+arr[l];
    else
        tl=dfs(l+2,r)+arr[l];

    if(arr[r-1]>arr[l])
        tr=dfs(l,r-2)+arr[r];
    else
        tr=dfs(l+1,r-1)+arr[r];
    return dp[l][r]=(tl>tr)?tl:tr;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
    int cas=0;
    while(~scanf("%d",&n) && n)
    {
        cas++;
        int sum=0;
        memset(arr,0,sizeof(arr));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            sum+=arr[i];
        }
        int s=dfs(0,n-1);
        int s2=sum-s;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",cas,s-s2);
    }
    return 0;
}
