#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int maxn=1e5+10;
int l[maxn],r[maxn];
bool inv;
int op,x,y;
int n,m;

void link(int L,int R)
{
    r[L]=R;
    l[R]=L;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa12657.in","r",stdin);
    //freopen("UVa12657.out","w",stdout);
#endif
    int cas=0;
    while(cin >> n >> m)
    {
        cas++;
        for(int i=1;i<=n;i++)
        {
            l[i]=i-1;
            r[i]=(i+1)%(n+1);
        }
        r[0]=1;
        l[0]=n;
        inv=0;
        while(m--)
        {
            cin >> op;
            if(op ==4)
                inv=!inv;
            else
            {
                cin >> x >> y;
                if(op==3 && r[y]==x)
                    swap(x,y);
                if(op!=3 && inv)
                    op=3-op;
                if((op==1 && x==l[y])||(op==2 && x==r[y]))
                    continue;
                int lx=l[x],rx=r[x],ly=l[y],ry=r[y];
                if(op==1)
                {
                    link(lx,rx);
                    link(ly,x);
                    link(x,y);
                }
                if(op==2)
                {
                    link(lx,rx);
                    link(y,x);
                    link(x,ry);
                }
                if(op==3)
                {
                    if(rx==y)
                    {
                        link(lx,y);
                        link(x,y);
                        link(x,ry);
                    }
                    else
                    {
                        link(lx,y);
                        link(y,rx);
                        link(ly,x);
                        link(x,ry);
                    }
                }
            }
        }
        int b=0;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            b=r[b];
            if(i%2)
                ans+=b;
        }
        if(inv && n%2==0)
            ans= ((ll)n*(n+1)/2)-ans;
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
