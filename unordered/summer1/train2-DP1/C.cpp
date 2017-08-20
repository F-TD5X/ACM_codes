#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[1111][1111][4];
int n,m;
int a[1111][1111];
int ans;
int main()
{
    cin >> n >> m;
    ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >>a[i][j];
    memset(dp,0,sizeof(dp));
    for(int i = 1,i1=1,i2=n,i3=n;i<=n && i1<=n&&i2>0&&i3>0;i++,i1++,i2--,i3--)
        for(int j=1,j1=m,j2=m,j3=1;j<=m && j1>0 && j2>0&&j3<=m;j++,j1--,j2--,j3++)
        {
            //i:1->n j:1->m
            dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0])+a[i][j];
            //i:1->n j:m->1
            dp[i1][j1][1]=max(dp[i1-1][j1][1],dp[i1][j1+1][1])+a[i1][j1];
            //i:n->1 j:m->1
            dp[i2][j2][2]=max(dp[i2+1][j2][2],dp[i2][j2+1][2])+a[i2][j2];
            //i:n->1 j:i->m
            dp[i3][j3][3]=max(dp[i3+1][j3][3],dp[i3][j3-1][3])+a[i3][j3];
        }
    for(int i=2;i<n;i++)
        for(int j =2;j<m;j++)
            ans = max(max(ans,dp[i][j-1][0]+dp[i-1][j][1]+dp[i][j+1][2]+dp[i+1][j][3]),max(ans,dp[i-1][j][0]+dp[i][j+1][1]+dp[i+1][j][2]+dp[i][j-1][3]));
    cout << ans <<endl;
}

