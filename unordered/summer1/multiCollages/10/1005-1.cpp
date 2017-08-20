#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=3e5;
int tree[maxn<<2],L[maxn],R[maxn],v[maxn],n,m,ans;
vector<int> in[maxn],out[maxn];

void update(int rt,int l,int r,int L,int R,int num)
{
    if(L<=l&&r<=R)
    {
        tree[rt]=num;return;
    }
    int mid=(l+r)>>1;
    if(tree[rt]!=-1)
    {
        tree[rt<<1]=tree[rt<<1|1]=tree[rt];
        tree[rt]=-1;
    }
    if(L<=mid)
        update(rt<<1,l,mid,L,R,num);
    if(m+1<=R)
        update(rt<<1|1,mid+1,r,L,R,num);
}

int query(int rt,int l,int r,int pos)
{
    if(l==r || tree[rt]!= -1)
        return tree[rt];
    int mid = (l+r)>>1;
    if(pos<=mid)
        return query(rt<<1,l,mid,pos);
    else
        return query(rt<<1|1,mid+1,r,pos);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1005-1.in","r",stdin);
    //freopen("1005-1.out","w",stdout);
#endif
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        memset(tree,-1,sizeof(tree));
        for(int i=0;i<=m+1;i++)
        {
            in[i].clear();
            out[i].clear();
        }
        for(int i=1;i<n;i++)
            scanf("%d",&v[i]);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&L[i],&R[i]);
            if(L[i] > R[i])
                swap(L[i],R[i]);
        }
        for(int i=m;i>=1;i--)
            update(1,1,n,L[i],R[i]-1,i);
        for(int i=1;i<n;i++)
        {
            int t= query(1,1,n,i);
            if(t!=-1)
                in[t].push_back(i);
        }
        memset(tree,-1,sizeof(tree));
        for(int i=1;i<=m;i++)
            update(1,1,n,L[i],R[i]-1,i);
        for(int i=1;i<n;i++)
        {
            int t = query(1,1,n,i);
            if(t!=-1)
                out[t].push_back(i);
        }
        for(int i=1;i<=m;i++)
        {
            for(auto x:in[i])
                ans+=v[x];
            printf("%d\n",ans);
            for(auto x:out[i])
                ans-=v[x];
        }
    }
    return 0;
}
