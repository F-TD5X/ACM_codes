#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include<map>
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1111;
struct Node
{
    int x,y;
}a[maxn],b[maxn];
int x,y,t,n,m;

bool yes;

int cmp(const Node &a,const Node &b)
{
    return a.y < b.y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
#endif
    scanf("%d",&t);
    while(t--)
    {
        yes =1;
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i].x;
            a[i].y = -1;
        }
        for(int i=1;i<=n;i++)
        {
            cin >> b[i].x;
            for(int j = 1;j<=n;j++)
            {
                if(a[j].x == b[i].x && a[j].y == -1)
                {a[j].y =i;break;}
            }
        }
        for(int i =0 ;i<m;i++)
        {
            cin >> x >> y;
            sort(a+x,a+y+1,cmp);
        }
        for(int i =1;i<=n;i++)
        {
            if(a[i].x != b[i].x)
            {
                yes =0;
                break;
            }
        }
        if(yes)
            cout <<"Yes"<<endl;
        else
            cout <<"No"<<endl;
    }
    return 0;
}
