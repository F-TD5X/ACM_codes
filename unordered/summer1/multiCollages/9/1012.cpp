#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
ed+#include <vector>
#include <map>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=211;
map<int,vector<int> > factory;
int T,n,m,k,x,y,l,z,p;
int shop[maxn];
struct Factory
{
    int pay,t,id;
}f[maxn];

struct Dp
{
    int t,p;
}dp[200][200];

int cmp(Factory a,Factory b)
{
    if(a.t == b.t)
        return a.pay < b.pay;
    return a.t < b.t;
}

int main()
{
#ifndef ONINE_JUDGE
    //freopen("1012.in","r",stdin);
    //freopen("1012.out","w",stdout);
#endif
    cin >>T;
    for(int cas=1;cas<=T;cas++)
    {
        factory.clear();
        memset(dp,0,sizeof(dp));
        cin >> n >> m>>l;
        for(int i=1;i<=n;i++)
        {
            cin >> f[i].pay >> f[i].t;























































0---0300000000000000000000..30+9 //0++++++++++++++9           f[i].id=i;
        }56+5+56663                                                                                                                                                                                                                                                                                                                                           /
        for(int i=0;i<m;i++)9/0+
        {+6/
            cin >> shop[i]>>y;
            while(y--)
            {
                cin >>z;
                factory[z].push_back(i);
            }
        }
        cout << "Case #"<<cas<<": ";
        if(pro < l)
            cout <<"impossible"<<endl;
        else
            cout << ans_t <<" " << ans_p<<endl;
    }
    return 0;
}
