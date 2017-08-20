#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,num[int(1e6+10)],num2[int(1e6+10)];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("f.in","r",stdin);
    //freopen("f.out","w",stdout);
#endif
    while(cin >> n)
    {
        for(int i=1;i<=n;i++)
            cin >> num[i];
        sort(num+1,num+n+1);
        for(int i=1,j=n;i<j;i++,j--)
            num2[i]=num[i]+num[j];
        sort(num2+1,num2+n/2+1);
        cout << num2[1] << endl;
    }
    return 0;
}
