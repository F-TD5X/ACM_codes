#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
    int ans,x,n;
    while(cin >> n)
    {
        ans =0;
        while(n--)
        {
            cin >>x;
            ans ^=x;
        }
        if(ans)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
