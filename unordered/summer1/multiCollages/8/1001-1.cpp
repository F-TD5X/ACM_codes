#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
struct Node
{
    int x,y;
}a[1111];
int b[1111];
int t,n,x,y,ini,m;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1001-1.in","r",stdin);
    //freopen("1001-1.out","w",stdout);
#endif
    cin >> t;
    while(t--)
    {
        cin >>n >> m;
        for(int i =1;i<=n;i++)
        {
            cin >> a[i].x;
            a[i].y=-1;
        }
    }
    return 0;
}
