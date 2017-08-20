#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
    int a,b;
    cin >>a >>b;
    cout << gcd(a,b)<<endl;
    return 0;
}
