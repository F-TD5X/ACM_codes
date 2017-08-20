#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,ans;
int euler(int n)
{
    int res=n,a=n;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            res=res/i*(i-1);
            while(a%i==0)
                a/=i;
        }
    }
    if(a>1)
        res=res/a*(a-1);
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1136.in","r",stdin);
    //freopen("1136.out","w",stdout);
#endif
    cin >> n;
    cout << euler(n)<<endl;
    return 0;
}
