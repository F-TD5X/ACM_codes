#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    int n,d,b,a,sum=0,ans=0;
    cin  >> n>>b>>d;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        sum+=a;
        if(sum >=d)
            sum=0,ans++;
    }
    cout << ans << endl;
    return 0;
}
