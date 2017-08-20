#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n;
ll arr[55555];
ll ans=0;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1344.in","r",stdin);
    //freopen("1344.out","w",stdout);
#endif
    cin >>n;
    int x;
    ll re=0;
    for(int i=0;i<n;i++)
    {
        cin >>x;
        if(re+x<0)
        {
            ans+=-x-re;
            re=0;
        }
        else
            re+=x;
    }
    cout <<ans << endl;
    return 0;
}
