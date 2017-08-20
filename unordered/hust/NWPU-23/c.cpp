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
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
#endif
    int a,b,c,d;
    while(cin >> a>>b && a+b)
    {
        if(a>b)
        {
            c=  a;
            a=b;
            b=c;
        }
        c=1.0*(b-a)*(sqrt(5.0)+1)/2;
        if(c == a)
            cout << "0"<<endl;
        else
            cout <<"1"<<endl;
            
    }
    return 0;
}
