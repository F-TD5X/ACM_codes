#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e6+10;
ll dfs(ll p,ll q,int step,int rest)
{
    if(p==q)return step;
    ll x=0;
    while((p - (1LL<<x)+1LL)>q)
        x++;
    if(max(p-(1LL<<x)+1LL,0LL)==q)
        return step+x;
    ll up=q-max(0LL,p-(1LL<<x)+1LL);
    ll tmp = max(0LL,up-rest);
    return min(tmp+x+step,dfs(p-(1LL<<(x-1))+1LL,q,step+x,rest+1));
}

int main()
{
    int n,m,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n<=m)
            cout << m-n<<endl;
        else
            cout << dfs(n,m,0,0) << endl;
    }
    return 0;
}
