#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000105;
const ll mod = 998244353;

int T;
ll l,r,k;
int vis[maxn];
vector<ll> v;
ll cal[maxn];

void init()  ///素数
{
    for(int i = 2; i < maxn; i++)
    {
        if(vis[i]) continue;
        v.push_back(i * 1LL);
        for(int j = i + i; j < maxn; j += i)
            vis[j] = 1;
    }
}

int getmul(ll x,ll b)
{
    int ret = 0;
    while(x % b == 0)
    {
        ret++;
        x /= b;
    }
    return ret;
}

int main()
{
	//freopen("1003.in","r",stdin);
	//freopen("1003.1.out","w",stdout);
    init();
    cin>>T;
    while(T--)
    {
        scanf("%lld%lld%lld",&l,&r,&k);
        memset(vis,0,sizeof vis);
        for(int i = 0; i < r - l + 1; i++) 
			cal[i] = 1;
        for(int i = 0; i < v.size() && v[i] <= r; i++)
        {
            ll x = (l / v[i]) * v[i];
            if(x < l) 
				x += v[i];
            for(;x <= r; x += v[i])
            {
                //cout<<k<<" "<<mul<<endl;
                cal[x-l] *= getmul(x,v[i]) * k + 1;
                cal[x-l] %= mod;
                vis[x-l] = 1;
            }
        }
        ll ans = 0;
        for(int i = 0; i < r - l + 1; i++)
            if(vis[i])
            {
                cout<<i<<" "<<cal[i]<<endl;
                ans = (ans + cal[i]) % mod;
            }
            else
                ans = (ans + k + 1) % mod;
        if(l == 1LL) ans -= k;
        cout<<ans<<endl;
    }
    return 0;
}
