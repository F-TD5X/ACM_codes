#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
string s1,s2;
int dp[1111][1111]={0};
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1092.in","r",stdin);
    //freopen("1092.out","w",stdout);
#endif
    cin >> s1;
    s2 = s1;
    int len=s1.size();
    reverse(s2.begin(),s2.end());
    memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=s1.size();i++)
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
   cout << s1.size()-dp[len][len]<<endl; 
    return 0;
}
