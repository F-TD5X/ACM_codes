#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+10;
struct Node
{
    ll l,r;
    ll num;
}tree[maxn<<2];
ll T,N,M,a[maxn],x,y;

void build(ll l,ll r,ll x)
{
    tree[x].l=l;tree[x].r=r;
    if(l == r)
    {
        tree[l].num = a[l];
        return;
    }
    ll mid = (l+r)>>1;
    build(l,mid,x*2);
    build(mid+1,r,x*2+1);
    tree[x].num = __gcd(tree[x*2].num,tree[x*2+1].num);
}

ll query(ll l,ll r,ll x)
{
    if(l <= tree[x].l && tree[x].r <= r)
        return tree[x].num;
    ll mid=(tree[x].l + tree[x].r)>>1;
    ll ans = 0;
    if(l<=mid) ans = __gcd(ans,query(l,r,x*2));
    if(mid<r) ans = __gcd(ans,query(l,r,x*2+1));
    return ans;
}

map<ll,ll> mp1,mp2,ans;

int main()
{
    cin >> T;
    for(ll cas = 1;cas<=T;cas++)
    {
        ans.clear();
        mp1.clear();
        mp2.clear();
        cin >> N;
        for(ll i=1;i<=N;i++)
            cin >> a[i];
        build(1,N,1);
        mp1[a[1]]++;
        ans[a[1]]++;
        for(ll i=2;i<=N;i++)
        {
            ll now=a[i];
            mp2[now]++;
            ans[now]++;
            for(map<ll,ll>::iterator it=mp1.begin(); it!=mp1.end(); it++)
            {
                ll nex=__gcd(now,it->first);
                ans[nex]+=it->second;
                mp2[nex]+=it->second;
            }
            mp1.clear();
            for(map<ll,ll>::iterator it=mp2.begin(); it!=mp2.end(); it++)
            {
                mp1[it->first]=it->second;
            }
            mp2.clear();
        }
        ll Q;
        cin >> Q;
        cout << "Case #"<<cas <<":"<<endl;
        while(Q--)
        {
            cin >> x >>y;
            ll t=query(x,y,1);
            cout << t <<" "<< ans[t] << endl;
        }
    }
}
