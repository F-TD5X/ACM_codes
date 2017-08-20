#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#define mkp(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
vector<ll> path;
map<ll ,ll> mp;
ll Q;
ll ans;

int main()
{
    ll u,v,w,n;
    cin >> Q;
    while(Q--)
    {
        cin >> n;
        if(n == 1)
        {
            cin >> u >> v>>w;
           while( v!= u)
           {
               if(v>u)
                {
                    ll t = v;
                    v = u;
                    u = t;
                }
                mp[u]+=w;
                u/=2;
           }
        }
        else if(n == 2)
        {
            ans =0;
            cin >> u >> v;
            while(v!=u)
            {
                if(v>u)
                {
                    ll t = v;
                    v = u;
                    u = t;
                }
                ans += mp[u];
                u /=2;
            }
            cout << ans << endl;
        }
    }
}
