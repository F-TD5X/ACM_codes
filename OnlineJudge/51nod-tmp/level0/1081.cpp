#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll tree[50000<<2],n,x;

ll get_sum(int n)
{
    ll ret=0;
    while(n)
    {
        ret+=tree[n];
        n-=(n&-n);
    }  
    return ret;
}

void add(ll x,ll num)
{
    while(x<=n)
    {
        tree[x]+=num;
        x+=(x&-x);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1081.in","r",stdin);
    //freopen("1081.out","w",stdout);
#endif
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x;
        add(i,x);
    }
    ll q,k,l;
    cin >> q;
    while(q--)
    {
        cin >> k >> l;
        cout << get_sum(l+k-1)-get_sum(k-1)<<endl;
    }
    return 0;
}
