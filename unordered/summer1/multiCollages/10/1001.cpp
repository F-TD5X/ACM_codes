#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e6;
int a[maxn],l1,r1,l2,r2,q,n,t;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
#endif
    cin >> t;
    int len1,len2;
    double mid;
    while(t--)
    {
        cin >> n>>q;
        for(int i=1;i<=n;i++)
            cin >>a[i];
        for(int i=0;i<q;i++)
        {
            cin >> l1>>r1>>l2>>r2;
            len1=r1-l1+1;
            len2=r2-l2+1;
            int m = (len1+len2)>>1;
            if((len1+len2)%2==0)
            {
               if(len1 > len2)
                   mid = (a[l1+m-1]+a[l1+m])/2.0;
               else if(len2>len1)
                   mid = (a[r2-m]+a[r2-m+1])/2.0;
               else if(len1 == len2)
                   mid = (a[r1]+a[l2])/2.0;
            }
            else
            {
                if(len1>len2)
                    mid = a[l1+((len1+len2)>>1)];
                else if(len1<len2)
                    mid = a[r2-((len1+len2)>>1)];
            }
            printf("%.1f\n",mid);
        }
    }
    return 0;
}
