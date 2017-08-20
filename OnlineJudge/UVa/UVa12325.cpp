#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long Gcd(long long u, long long v)
{
    if(u<v)
    {
        long long t=u;
        u=v;
        v=t;
    }
    long long remainder;
    remainder = u % v;
    while(remainder)
    {
        u = v;
        v = remainder;
        remainder = u % v;
    }
    return v;
}
long long gcd(long long u, long long v)
{
    return u * v / Gcd(u, v);
}
int main()
{
    long long n,v1,s1,v2,s2,T,sum,s,sum1;
    scanf("%lld",&T);
    long long tt=0;
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld",&n,&s1,&v1,&s2,&v2);
        long long value=0,va=0;
        s=gcd(s1,s2);
        long long temp=n/s;
        n%=s;
        if(temp)
        {
            temp--;
            n+=s;
        }
        value=temp*max(s/s1*v1,s/s2*v2);
        if(s1<s2)
        swap(s1,s2),swap(v1,v2);
        for(int i=0; i<=n/s1; i++)
            va=max((n-i*s1)/s2*v2+i*v1,va);
        value+=va;
        printf("Case #%lld: %lld\n",++tt,value);
    }
    return 0;
}
