#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e5;
int x1,x2,y1,y2,n,R,C;
struct Line
{
    int x1,y1,x2,y2;
    Line(int x1=0,int y1=0,int x2=0,int y2=0):x1(x1),y1(y1),x2(x2),y2(y2){}
}row[maxn],col[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1006.in","r",stdin);
    //freopen("1006.out","w",stdout);
#endif
    while(scanf("%d",&n)!=EOF)
    {
        R=C=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2)
                col[C++]=Line(x1,y1,x2,y2);
            else
                row[R++]=Line(x1,y1,x2,y2);
        }
    }
    return 0;
}
