#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=2e5+10;
int n,m;
struct Node
{
    int o,c;
}road[1000];
int r[maxn];
int a,b;
ll ans=0;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1005.in","r",stdin);
    //freopen("1005.out","w",stdout);
#endif
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i=0;i<=1000;i++)
        {
            road[i].o = 1e9;
            road[i].c=0;
        }
        memset(r,0,sizeof(r));
        for(int i=1;i<n;i++)
            scanf("%d",&r[i]);
        for(int i=1;i<=m;i++)
        {
            ans=0;
            scanf("%d%d",&a,&b);
            for(int j=a;j<b;j++)
            {
                road[j].o=min(road[j].o,i);
                road[j].c=max(road[j].c,i);
            }
        }
        for(int i=1;i<=m;i++)
        {
            ans=0;
            for(int j=1;j<n;j++)
            {
                if(road[j].o <= i && road[j].c >= i)
                    ans+=r[j];
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
