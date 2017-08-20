#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn= 1e6+10;
int a[maxn],n,ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
    int T;
    cin >>T;
    while(T--)
    {
        cin >> n;
        ans =0;
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        if(n%2==1)
        {   
            ans ^=a[0]-1;
            for(int i=1;i<n;i++)
            {
                ans^= a[i+1]-a[i]-1;
                i++;
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                ans ^= a[i+1]-a[i]-1;
                i++;
            }
        }
        if(!ans)
            puts("Bob will win");
        else
            puts("Georgia will win");
    }
    return 0;
}
