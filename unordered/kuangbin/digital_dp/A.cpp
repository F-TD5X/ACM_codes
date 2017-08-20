#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MOD = 2520;

ll dp[21][MOD][50];
int ind[MOD+5],digit[21];

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

ll dfs(int pos,int presum,int prelcm,bool edge)
{
    ll &x = dp[pos][presum][ind[prelcm]];
    if(pos == -1)    
        return presum%prelcm == 0;
    if(!edge && x !=-1)
        return x;
    int end = edge ? digit[pos] : 9;
    ll ans = 0;
    for(int i = 0; i <= end; ++i) {
        ans += dfs(pos - 1, (presum*10 + i)%MOD, i?lcm(prelcm,i):prelcm, edge && i == end);
    }
    return !edge?x=ans:ans;
}

ll solve(ll n)
{
    memset(digit,-1,sizeof(digit));
    int len=0;
    while(n)
    {
        digit[len++]=n%10;
        n/=10;
    }
    return dfs(len-1,0,1,1);
}

void init()
{
    int num=0;
    for(int i=1;i<=MOD;i++)
        if(MOD%i==0)
            ind[i]=num++;
    memset(dp,-1,sizeof(dp));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    init();
    int T;
    cin >> T;
    ll a,b;
    while(T--)
    {
        cin >> a >> b;
        cout << solve(b)-solve(a-1) << endl;
    }
    return 0;
}

