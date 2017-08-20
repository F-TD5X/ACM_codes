#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
struct node 
{
    int l,r,id;
    bool operator < (const node a) const 
    {
        return r<a.r;
    }
}q[N];
map<int,int>M;
int n,a[N],f[N],pre[N],xo[N],ans[N];

void add(int x,int y) 
{
    for (;x<=n;x+=x&-x) f[x]^=y;
}

int get(int x) 
{
    int ret=0;
    for (;x;x-=x&-x) ret^=f[x];
    return ret;
}

int main()
{
    int i,k,m;
    scanf("%d", &n);
    for (i=1;i<=n;i++) 
        scanf("%d", &a[i]),xo[i]=xo[i-1]^a[i];
    for (i=1;i<=n;i++) 
        pre[i]=M[a[i]],M[a[i]]=i;
    scanf("%d", &m);
    for (i=1;i<=m;i++) 
        scanf("%d%d", &q[i].l, &q[i].r),q[i].id=i;
    sort(q+1,q+m+1);
    for (k=1,i=1;i<=m;i++) 
    {
        for (;k<=n&&k<=q[i].r;k++) 
        {
            if (pre[k]) add(pre[k],a[k]);add(k,a[k]);
        }
        ans[q[i].id]=xo[q[i].r]^xo[q[i].l-1]^get(q[i].r)^get(q[i].l-1);
    }
    for (i=1;i<=m;i++) printf("%d\n", ans[i]);
    return 0;
}
