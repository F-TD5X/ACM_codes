#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 2e5+10;
int tree[maxn];
int p1[maxn],p2[maxn],p3[maxn];
int n;

void add(int x,int num)
{
    while(x <=n)
    {
        tree[x]+=num;
        x+=x&-x;
    }
}

int getsum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=tree[x];
        x-=x&-x;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
    scanf("%d",&n);
    int x;
    for(int i=1;i<=n;i++)
        add(i,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        p1[i]=getsum(x);
        add(x+1,-1);
    }
    memset(tree,0,sizeof(tree));
    for(int i=1;i<=n;i++)
        add(i,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        p2[i]=getsum(x);
        add(x+1,-1);
    }
    for(int i=n;i>=1;i--)
    {
        p3[i]+=p1[i]+p2[i];
        if(p3[i]>=n+1-i)
        {
            p3[i]=p3[i]-n-1+i;
            if(i!=1)
                p3[i-1]++;
        }
    }
    memset(tree,0,sizeof(tree));
    for(int i=1;i<=n;i++)
        add(i,1);
    int a,b,c;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=n;
        while(l<=r)
        {
            int m=(l+r)>>1;
            a= getsum(m);
            b=getsum(m-1);
            if(b > p3[i] || (b == p3[i] && a-b==1))
                r=m-1;
            else if((b==p3[i] && a-b <1)||b<p3[i])
                l=m+1;
        }
        add(l,-1);
        printf("%d ",l-1);
    }
    printf("\n");
    return 0;
}

