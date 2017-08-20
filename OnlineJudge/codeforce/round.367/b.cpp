#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e5+10;
int sum[maxn],a[maxn];
int n,q,x;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
#endif
    while(cin >> n)
    {
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            sum[a[i]]++;
        }
        for(int i=0;i<maxn;i++)
        {
            sum[i]+=sum[i-1];
        }
        cin >> q;
        for(int i=0;i<q;i++)
        {
            cin >> x;
            if(x >= maxn)
                cout << sum[maxn-1] << endl;
            else
                cout << sum[x] << endl;
        }
    }
    return 0;
}
