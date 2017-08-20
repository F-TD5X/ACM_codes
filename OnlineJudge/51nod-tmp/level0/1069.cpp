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
    //freopen("1069.in","r",stdin);
    //freopen("1069.out","w",stdout);
#endif
    int p=0;
    int n,x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        p^=x;
    }
    cout << (p==0?"B":"A")<<endl;
    return 0;
}
