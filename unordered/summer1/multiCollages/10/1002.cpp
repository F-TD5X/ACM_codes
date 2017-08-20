#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define PI 3.1415926535897932384626
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1002.in","r",stdin);
    //freopen("1002.out","w",stdout);
#endif
    int T;
    cin >> T;
    double l,r1,r2,s1,s2,a,b,c,d,e;
    while(T--)
    {
        cin >> l;
        r1 = l;
        r2 = l/2;
        d = sqrt(r2*r2*2);
        a = acos(d*d+r1*r1-r2*r2)/(2*d*r1);
        b = acos(d*d+r2*r2-r1*r1)/(2*d*r2);
        s1=r2*r2*r2;
        s2=0;
        c=r2*r2*sin(a)*cos(a);
        e=r1*r1*sin(b)*cos(b);
        cout << r2*r2- s1+s2-(c+e) << endl;
    }
    return 0;
}
