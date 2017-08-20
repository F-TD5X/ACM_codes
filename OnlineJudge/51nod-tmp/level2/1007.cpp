#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int dp[11111];
int a[111];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1007.in","r",stdin);
    //freopen("1007.out","w",stdout);
#endif
    int n;
    int sum=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++)
        for(int j=sum>>1;j>=a[i];j--)
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
    cout <<fabs(sum-dp[sum>>1]) - dp[sum>>1]<<endl;
    return 0;
}
