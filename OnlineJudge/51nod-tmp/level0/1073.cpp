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
    //freopen("1073.in","r",stdin);
    //freopen("1073.out","w",stdout);
#endif
    int n,k,ans=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+k)%i;
    }
    cout << ans+1 << endl;
    return 0;
}
