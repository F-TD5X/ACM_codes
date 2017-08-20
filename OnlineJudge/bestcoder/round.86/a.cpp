#include <iostream>
#include<cstdio>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll v[100010],x,p;
ll n,m,T;
int main()
{
    scanf("%I64d",&T);
    while(T--)
    {
        p=0;
        scanf("%d%d",&n,&m);
        for(ll i = 0;i<n;i++)
        {
            scanf("%I64d",&x);
            p +=x;
        }
        for(ll i=0;i<m;i++)
        {
            scanf("%I64d",&x);
            if(x > p)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    return 0;
}
