#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int solve(int n)
{
    int ret=0;
    while(n)
    {
        ret+=n/5;
        n/=5;
    }
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif
    int n;
    cin >> n;
    cout << solve(n)<<endl;
    return 0;
}
