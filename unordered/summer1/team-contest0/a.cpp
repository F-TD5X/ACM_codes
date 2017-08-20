#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include<string>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e6+10;
int n,m;
string s;
double p[maxn];
int vi[maxn];
double ans1,ans2;
double dp[maxn],o[maxn][2];
double least;

double fun(int x)
{
    double &ret=dp[x];
    if(vi[x])
        return ret;
    vi[x]=1;
    if(x>n)
        return ret=0;
    ret = max(log(1+1.0*o[x][1]/m),fun(x+1));
    ret = (1-p[x])*log(1+1.0*o[x][0]/m)+p[x]*ret;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
#endif
    cin >> n >>m;
        for(int i=1;i<=n;i++)
        {
            cin >> s >> p[i] >> o[i][1];
            o[i][0]=least;
            if(s == "safe")
                least = o[i][1];
        }
        ans1= fun(1);
        ans2 = (exp(ans1)-1)*m;
        printf("%.2f\n",ans2);
    return 0;
}
