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
    double x,y;
    int id,id1,type;
    ll d;
}tree[111],ant[111],p[400];
int n,ans[111];

int cross(Node a,Node b)
{
    return a.x*b.y-b.x*a.y;
}

int cmp(Node a,Node b)
{
    Node p={0,0,0};
    if(cross(a,b)==0)
        return a.d>b.d;
    return cross(a,b)<0;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    cin >> n;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        /*cin >> ant[i].x >> ant[i].y;
        ant[i].x+=20000;
        ant[i].y+=20000;
        ant[i].d=ant[i].x*ant[i].x+ant[i].y*ant[i].y;
        ant[i].id=i+1;
        */
        cin >> p[cnt].x >> p[cnt].y;
        p[cnt].x+=20000;
        p[cnt].y+=20000;
        p[cnt].d=p[cnt].x*p[cnt].x+p[cnt].y*p[cnt].y;
        p[cnt].type=0;
        p[cnt++].id=i+1;
    }
    for(int i=0;i<n;i++)
    {
        /*
        cin >> tree[i].x >> tree[i].y;
        tree[i].x+=20000;
        tree[i].y+=20000;
        tree[i].d=tree[i].x*tree[i].x+tree[i].y*tree[i].y;
        tree[i].id=i+1;
        */
        cin >> p[cnt].x >> p[cnt].y;
        p[cnt].x+=20000;
        p[cnt].y+=20000;
        p[cnt].d=p[cnt].x*p[cnt].x+p[cnt].y*p[cnt].y;
        p[cnt].type=1;
        p[cnt++].id1=i+1;
    }
    sort(ant,ant+n,cmp);
    sort(tree,tree+n,cmp);
    sort(p,p+cnt,cmp);
    int tt=0;
    for(int i=0;i<cnt;i++)
    {
        if(p[i].type==1)
        {
            for(;tt<cnt;tt++)
            {
                if(p[tt].type==0)
                    ans[p[i].id]=p[tt].id1;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout << ans[i]<<endl;
    return 0;
}
