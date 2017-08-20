#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[3],b[3];
bool yes;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("i-1.in","r",stdin);
    //freopen("i-1.out","w",stdout);
#endif
    while(cin >>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2])
    {
        yes=0;
        sort(a,a+3);
        sort(b,b+3);
        if(a[0]*a[0]+a[1]*a[1] == a[2]*a[2] && b[0]*b[0]+b[1]*b[1]==b[2]*b[2])
        {
            if(memcmp(a,b,sizeof(a)) == 0)
                yes=1;
        }
        if(yes)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
