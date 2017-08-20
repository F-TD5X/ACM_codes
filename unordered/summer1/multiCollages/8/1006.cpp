#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e5+10;
int a,b,v[maxn];
int T,Q,t,k,n,C;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1006.in","r",stdin);
    //freopen("1006.out","w",stdout);
#endif
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&C);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",v+i,&a,&b);
        }
        sort(v+1,v+1+n);
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d%d",&t,&k);
            printf("%.3f\n",sqrt(1LL*2*t*C + 1LL*v[k]*v[k]));
        }
    }
    return 0;
}
