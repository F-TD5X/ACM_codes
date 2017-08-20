#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 2520;

LL dp[21][MOD][50];
int digit[21];
int indx[MOD+5];

void init() {
    int num = 0;
    for(int i = 1; i <= MOD; ++i) {
        if(MOD%i == 0) indx[i] = num++;
    }
    memset(dp,-1,sizeof(dp));
}

LL gcd(LL a, LL b) {
    return b==0?a:gcd(b,a%b);
}

LL lcm(LL a, LL b) {
    return a/gcd(a, b)*b;
}

LL dfs(int pos, int presum, int prelcm, bool edge) {
    if(pos == -1)    return presum%prelcm == 0;
    if(!edge && dp[pos][presum][indx[prelcm]] != -1)
        return dp[pos][presum][indx[prelcm]];
    int ed = edge ? digit[pos] : 9;
    LL ans = 0;
    for(int i = 0; i <= ed; ++i) {
        int nowlcm = prelcm;
        int nowsum = (presum*10 + i)%MOD;
        if(i)   nowlcm = lcm(prelcm, i);
        ans += dfs(pos - 1, nowsum, nowlcm, edge && i == ed);
    }
    if(!edge)    dp[pos][presum][indx[prelcm]] = ans;
    return ans;
}

LL cal(LL x) {
    memset(digit,-1,sizeof(digit));
    int pos = 0;
    while(x) {
        digit[pos++] = x%10;
        x /= 10;
    }
    return dfs(pos - 1, 0, 1, 1);
}

int main()
{
    init();
    int T;
    LL a, b;
    cin >> T;
    while(T--) {
        cin >> a >> b;
        cout << cal(b) - cal(a - 1) << endl;
    }
    return 0;
}
