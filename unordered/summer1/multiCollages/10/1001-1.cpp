#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[1000000];
int n,q,T,l1,r1,l2,r2;
double mid;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1001.in","r",stdin);
    freopen("1001","w",stdout);
#endif
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        while(q--)
        {
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            int len1=r1-l1+1,len2=r2-l2+1,len=len1+len2;
            int m=len>>1;
            if(len%2==0)
            {
                if(m>len1)
                    mid = (1.0*a[r2-m+1]+1.0*a[r2-m])/2.0;
                else if(m == len1)
                    mid = (1.0*a[r1]+1.0*a[l2])/2.0;
                else
                     mid =(1.0*a[l1+m]+1.0*a[l1+m-1])/2.0;
            }
            else
            {
                if(m >=len1)
                    mid = 1.0*a[r2-m];
                else
                    mid = 1.0*a[l1+m];
            }
            printf("%.1f\n",mid);
        }
    }
    return 0;   
}
