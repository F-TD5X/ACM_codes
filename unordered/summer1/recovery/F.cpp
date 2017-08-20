#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = pow(2,16)+10;
vector<pair<ll,ll> >ans;
queue<ll> q;
int d[maxn],v[maxn];
bool u[maxn];
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
    cin >> n;
    for(ll i =0;i<n;i++)
    {
        cin >> d[i]>>v[i];
        if(d[i]<2)
        {
            q.push(i);
            u[i]=1;
        }
    }
    int t,tt,ttt;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(d[t]==0)
            continue;
        tt=v[t];
        v[tt] ^=t;
        d[t]--;
        d[tt]--;
        ans.push_back(make_pair(t,tt));
        if(d[tt]<2 && !u[tt])
        {
            q.push(tt);
            u[tt]=1;
        }
    }
    cout << ans.size() << endl;
    for(auto a:ans)
    {
        cout << a.first <<" " << a.second << endl;
    }
    return 0;
}
