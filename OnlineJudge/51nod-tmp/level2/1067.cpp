#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1067.in","r",stdin);
    //freopen("1067.out","w",stdout);
#endif
    int t;
    cin >> t;
    int n;
    while(t--)
    {
        cin >> n;
        if(n%7==0 || n%7==2)
            puts("B");
        else
            puts("A");
    }
    return 0;
}
