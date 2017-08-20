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
    //freopen("1072.in","r",stdin);
    //freopen("1072.out","w",stdout);
#endif
    int t,a,b;
    cin >> t;
    while(t--)
    {
        cin >> a>>b;
        if(a>b)
            swap(a,b);
        if(a ==(int)((b-a)*(sqrt(5)+1)/2))
       puts("B");
        else
            puts("A");
    }
    return 0;
}
