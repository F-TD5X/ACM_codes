#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 25;
ll a[maxn],m[maxn];
int s[maxn],n;
ll extend_Euclid(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    ll r=extend_Euclid(b,a%b,y,x);
    y-=a/b*x;
    return r;
}

ll quick_multi(ll a,ll k,ll m)
{
    ll ret=0;
    while(k)
    {
        if(k & 1LL)
            ret = (ret+a)%m;
        k>>=1;
        a=(a<<1)%m;
    }
    return ret;
}

ll China(ll l,ll r)
{
    ll M=1,ans =0;
    for(int i=0;i<=n;i++)
        if(s[i])
            M*=m[i];
    ll w;
    for(int i=0;i<=n;i++)
    {
        if(s[i])
        {
            w = M/m[i];
            ll x,y;
            extend_Euclid(w,m[i],x,y);
            x = (x%m[i]+m[i])%m[i];
            ans = ((ans + quick_multi(a[i]*w%M,x,M))%M+M)%M;
        }
    }
    return (r+M-ans)/M - (l-1+M-ans)/M;
}

int main()

{
    int T;
    cin >> T;
    for(int cas =1;cas <=T;cas++)
    {
        ll l,r;
        cin >> n >> l >> r;
        memset(s,0,sizeof(s));
        m[n]=7;a[n]=0;s[n]=1;
        for(int i=0;i<n;i++)
            cin >> m[i] >> a[i];
        ll ans =0;
        int all = 1<<n;
        for(int i=0;i<all;i++)
        {
            int t=i,k=0;
            for(int j=0;j<n;j++)
            {
                s[j] = t&1;
                t>>=1;
                k+=s[j];
            }
            k = k&1?-1:1;
            ans += 1LL*k*China(l,r);
        }        
        cout <<"Case #"<<cas <<": " << ans << endl;
    }
    return 0;
}
