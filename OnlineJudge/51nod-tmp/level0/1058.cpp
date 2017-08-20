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
    //freopen("1058.in","r",stdin);
    //freopen("1058.out","w",stdout);
#endif
    int n;
    double ans=1;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        ans+=log(i)/log(10);
    }
    ll out=ans;
    cout << out << endl;
    return 0;
}
