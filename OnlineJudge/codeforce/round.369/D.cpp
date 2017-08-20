#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=2*1e5+10;
const int mod=1e9+7;
int f[maxn],m;
int ma[maxn];
int v[maxn],nx[maxn];
int n;

int ad(int a,int b)
{
    ++m;
    nx[m]=f[a];
    f[a]=m;
    v[m]=b;
}

int c[maxn],d[maxn];

int add(int a,int b)
{
    ++c[a];++c[b];
    ad(a,b);ad(b,a);
}

int cn()
{
    int h=0,t=0;
    for(int i=1;i<=n;i++)
        if(c[i]==1)
        {
            c[i]=0;d[t++]=i;
        }
    while(h!=t)
    {
        int x=d[h++];
        for(int e=f[x];e;e=nx[e])
        {
            int tt=v[e];
            c[tt]--;
            if(c[tt]==1)
            {
                c[tt]=0;
                d[t++]=tt;
            }
        }
    }
}

int ft[maxn];

int fi(int x)
{
    return ft[x]?ft[x]=fi(ft[x]):x;
}

int uni(int x,int y)
{
    int fx=fi(x),fy=fi(y);
    if(fx!=fy)
        ft[fy]=fx;
}

int cnt[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> ma[i];
        add(i,ma[i]);
        uni(i,ma[i]);
    }
    cn();
    int ff=n;
    for(int i=1;i<=n;i++)
        if(c[i]==2)
        {
            --ff;cnt[fi(i)]++;
        }
    ll ans=1;
    for(int i=1;i<=ff;i++)
        ans=ans*2%mod;
    for(int i=1;i<=n;i++)
    {
        if(!cnt[i])
            continue;
        ll tmp=1;
        for(int j=1;j<=cnt[i];j++)
            tmp=tmp*2%mod;
        tmp=(tmp-2)%mod;
        if(tmp)
            ans=ans*tmp%mod;
    }
    ans=(ans%mod+mod)%mod;
    cout << ans << endl;
    return 0;
}
