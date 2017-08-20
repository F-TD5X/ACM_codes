#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,k;
const int mod=1e9+7;

class M
{
    public:
    ll m[111][111];
    M()
    {
        for(int i=0;i<n;i++)
            m[i][i]=1;
    }
    M operator*(M b)
    {
        M c;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                int t=0;
                for(int k=0;k<n;k++)
                    t=(t+m[i][k]*b.m[k][j])%mod;
                c.m[i][j]=t;
            }
        return c;
    }

    M operator^(int k)
    {
        M t=*this;
        M ret;
        while(k)
        {
            if(k%2==1)
            {
                ret =ret*t;
            }
            k/=2;
            t=t*t;
        }
        return ret;
    }
}mm;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1113.in","r",stdin);
    //freopen("1113.out","w",stdout);
#endif
    cin >> n >> k;
    M ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> mm.m[i][j];
    ans=mm^k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << ans.m[i][j]<<" ";
        cout << endl;
    }

    return 0;
}
