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
int n,h,low,high,x;
string s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
#endif
    while(cin >> n >> h)
    {
        high =1e9;
        low=1;
        for(int i=0;i<n;i++)
        {
            cin >> x >> s;
            if(s == "SAFE")
            {
                low = max(low ,x);
            }
            if(s == "BROKEN")
            {
                high = min(high,x);
            }
        }
        cout << low+1<<" ";
        if(high-1 == low)
            cout << low << endl;
        else if(high > h)
            cout << h-1 << endl;
        else 
            cout << high-1 << endl;
    }
    return 0;  
}
