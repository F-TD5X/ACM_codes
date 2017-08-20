#include<bits/stdc++.h>
using namespace std;
int a[105][105],d[105][105],C;
int n;
int solve(int i,int j)
{
    if(d[i][j] >=0) return d[i][j];
    return d[i][j] = a[i][j]+(i ==n?0:max(solve(i+1,j),solve(i+1,j+1)));
}
int main()
{
    cin >>C;
    while(C--)
    {
        cin >> n;
        memset(d,-1,sizeof(d));
        for(int i =1;i<=n;i++)
          for(int j = 1;j<=i;j++)
            cin >> a[i][j];
        cout << solve(1,1)<<endl;
    }
}
