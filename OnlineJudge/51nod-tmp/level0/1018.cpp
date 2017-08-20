#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[55555];int n;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1018.in","r",stdin);
    //freopen("1018.out","w",stdout);
#endif
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
        cout << a[i]<<endl;
    return 0;
}
