#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m,a[6010],i;
bool prime(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return 0;
    return 1;
}
int main()
{
    cin>>n;
    m=n*(n+1)/2;
    for(i=1;i<=n;i++) a[i]=1;
    if(!prime(m))
    {
        if((m&1)&&!prime(m-2)) m-=3,a[3]=3;
        for(i=2;i<m;i++)
            if(prime(i)&&prime(m-i)) {a[i]=2; break;}
    }
    for(i=1;i<=n;i++) cout<<a[i]<<' ';
}
