#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e4+19;
int tree[maxn<<2],n,q,x,a[maxn];
int build(int rt,int l,int r)
{
    if(l==r)
        return tree[rt]=a[l];
    else
    {
        int m=(l+r)>>1;
        build(rt<<1,l,m);
        build(rt<<1|1,m+1,r);
        tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
    }
}

int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
        return tree[rt];
    else if(l>R || r<L)
        return 0;
    else
    {
        int m=(l+r)>>1;
        return max(query(rt<<1,l,m,L,R),query(rt<<1|1,m+1,r,L,R));
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1174.in","r",stdin);
    //freopen("1174.out","w",stdout);
#endif
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    cin >> q;
    build(1,1,n);
    int l,r;
    while(q--)
    {
        cin >>l>>r;
        cout << query(1,1,n,l+1,r+1)<<endl;
    }
    return 0;
}
