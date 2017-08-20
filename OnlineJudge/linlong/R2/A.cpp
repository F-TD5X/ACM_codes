#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e5+20;
int n,m;
int a1[maxn],a2[maxn];
ll mod = pow(2,40);
ll ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    int T;
    cin >> T;
    for(int cas=1;cas<=T;cas++)
    {
        cin >> n >>m;
        for(int i=1;i<=n;i++)
            cin >> a1[i];
        for(int i=1;i<=m;i++)
        {
            cin >> a2[i];
            a2[i]=-a2[i];
            for(int j=1;j<=n;j++)
            {
                ans += fabs((a1[j]^a2[i])+(a1[j]&a2[i])*2)*fabs(i-j);
                ans %=mod;
            }
        }
        /*
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                ans += fabs((a1[i]^(-1*a2[j]))+(a1[i]&(-1*a2[j]))*2)*fabs(i-j);
                ans %=mod;
            }
            */
        printf("Case #%d:%I64d\n",cas,ans);
    }
    return 0;
}
