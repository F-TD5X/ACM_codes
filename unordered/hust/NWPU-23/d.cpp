#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int ans,n,x,f[int(1e6+10)];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
    while(cin >> n && n)
    {
        memset(f,0,sizeof(f));
        ans =0;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            if(f[x])
                ans--;
            else
                ans++;
            f[x] = !f[x];
        }
        if(ans)
            puts("1");
        else
            puts("0");
    }  
    return 0;
}
