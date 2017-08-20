#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int ext_gcd(int a,int b,int &x,int&y)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    int ans=ext_gcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1256.in","r",stdin);
    //freopen("1256.out","w",stdout);
#endif
    int a,b,x,y;
    cin >> a>>b;
    ext_gcd(a,b,x,y);
    while(x<0)
        x+=b;
    cout << x%b<<endl;
    return 0;
}
