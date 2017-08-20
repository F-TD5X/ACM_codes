#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int pre,now,n;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1087.in","r",stdin);
    //freopen("1087.out","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n==1||n==2)
        {
            puts("1");
            continue;
        }
        now=0;
        while(now*(now+1)/2 <= n)
        {
            pre=now;
            now++;
        }
        if(now*(now+1)/2==n)
            puts("0");
        else if(pre*(pre+1)/2+1==n)
            puts("1");
        else
            puts("0");
    }
    return 0;
}
