#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1111;
int n;
double t[maxn],min_t=1e9,v,x,y,xx,yy;
double dis;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
#endif
    cin >> xx >> yy;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x>>y >> v;
        dis = sqrt((x-xx)*(x-xx) + (y-yy)*(y-yy));
        min_t = min(min_t,dis/v);
    }
    printf("%.15f\n",min_t);
    return 0;
}
