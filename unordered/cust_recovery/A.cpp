/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int a[55];  
    char s[55];  
	cin >> s;
    int len = strlen(s);  
    int ans = 0x3f3f3f3f;  
    for(int i = 0; i < len;i++)
        a[i] = s[i] - '0';  
    int dp[55];  
    for(int i = 0; i < len; i++)  {
        memset(dp, 0x3f3f3f3f, sizeof(dp));  
        for(int j = i; j < len; j++){  
            int pos = lower_bound(dp, dp + len, a[j]) - dp;  
            dp[pos] = a[j];  
        }  
        int temp = 26 - (lower_bound(dp, dp + len, 0x3f3f3f3f) - dp);  
        ans = min(ans, temp);  
    }  
    printf("%d\n", ans);  
	return 0;
}
