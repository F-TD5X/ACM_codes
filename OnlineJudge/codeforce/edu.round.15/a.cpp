#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int len1,len2,ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
#endif
    int n,x,y,z;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >>x;
        if(x > y)
        {
            y = x;
            len1++;
        }
        else
        {
            len2=max(len1,len2);
            len1=1;
            y=x;
        }
    }
    len2=max(len1,len2);
    cout << len2<<endl;
    return 0;
}
