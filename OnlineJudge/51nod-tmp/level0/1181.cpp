#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e6+10;
int t[maxn],cnt,prime[maxn];

bool isPrime(int n)
{
    if(n==1 || n==2)
        return 1;
    for(int i=2;i<n;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int init()
{
    memset(t,1,sizeof(t));
    for(int i=2;i<maxn;i++)
    {
        if(t[i])
        {
            int tt=i*2;
            while(tt<=maxn)
            {
                t[tt]=0;
                tt+=i;
            }
        }
    }
    for(int i=1;i<maxn;i++)
    {
        if(t[i])
        {
            prime[cnt++]=i;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1181.in","r",stdin);
    //freopen("1181.out","w",stdout);
#endif
    init();
    int n;
    int *loc;
    cin >> n;
    int l=upper_bound(prime+1,prime+cnt,n)-prime;
    if(prime[l-1] == n)
        l--;
    for(int i=l;i<cnt;i++)
    {
        if(*lower_bound(prime+1,prime+cnt,i)==i)
        {
            cout << prime[i] << endl;
            return 0;
        }
    }
    return 0;
}
