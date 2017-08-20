#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node
{
    int l,r;
    ll __gcd;
}Tree[maxn<<2];

ll a[maxn];

void Build(int l,int r,int rt)
{
    Tree[rt].l=l,Tree[rt].r=r;
    if(l==r)
    {
        Tree[rt].__gcd=a[l];
        return ;
    }
    int mid=(l+r)/2;
    Build(l,mid,rt*2);
    Build(mid+1,r,rt*2+1);
    Tree[rt].__gcd=__gcd(Tree[rt*2].__gcd,Tree[rt*2+1].__gcd);
}

ll queryans(int L,int R,int rt)
{
    if(L<=Tree[rt].l&&Tree[rt].r<=R)
    {
        return Tree[rt].__gcd;
    }
    int mid=(Tree[rt].l+Tree[rt].r)/2;
    ll ans=0;
    if(L<=mid) ans=__gcd(ans,queryans(L,R,rt*2));
    if(mid<R)  ans=__gcd(ans,queryans(L,R,rt*2+1));
    return ans;
}

int n;
map<ll,ll>mp1,mp2,ans;

int main()
{
    //freopen("1004.in","r",stdin);
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d",&n);
        ans.clear();
        mp1.clear();
        mp2.clear();
        for(int i=1; i<=n; i++) scanf("%I64d",&a[i]);
        Build(1,n,1);
        mp1[a[1]]++;
        ans[a[1]]++;
        for(int i=2; i<=n; i++)
        {
            ll now=a[i];
            mp2[now]++;
            ans[now]++;
            for(map<ll,ll>::iterator it=mp1.begin(); it!=mp1.end(); it++)
            {
                int nex=__gcd(now,it->first);
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
        int q;
        printf("Case #%d:\n",cas++);
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            ll temp=queryans(l,r,1);
            printf("%I64d %I64d\n",temp,ans[temp]);
        }
    }
}
