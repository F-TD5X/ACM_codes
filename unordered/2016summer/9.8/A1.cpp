#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
struct P
{
    double x,y;
    int id;
}a[111],t[111];

struct L
{
    double k;
    int a,t;
}l[11111];

int ut[111],ua[111],ans[111];
int n;

int cmp(L a,L b)
{
    return fabs(a.k)<fabs(b.k);
}
int cmp1(P a,P b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);
#endif
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >>a[i].x>>a[i].y;
        a[i].id=i+1;
    }
    for(int i=0;i<n;i++)
    {
        cin >> t[i].x >> t[i].y;
        t[i].id=i+1;
    }
    //sort(a,a+n,cmp1);
    //sort(t,t+n,cmp1);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                l[cnt].k=(a[i].y-t[j].y)/(a[i].x-t[j].x);
                l[cnt].a=i;
                l[cnt].t=j;
                cnt++;
            }
        }
    }
    sort(l,l+cnt,cmp);
    for(int i=0;i<cnt;i++)
    {
        if(!ua[l[i].a] && !ut[l[i].t])
        {
            ua[l[i].a]=1;
            ut[l[i].t]=1;
            ans[a[l[i].a].id]=t[l[i].t].id;
        }
    }
    for(int i=1;i<=n;i++)
        cout << ans[i] << endl;
    return 0;
}
