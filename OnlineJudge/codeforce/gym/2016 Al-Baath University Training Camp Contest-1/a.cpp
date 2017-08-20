#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int t,n,k,x;
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
#endif
    cin >> t;
    while(t--)
    {
        ans= 1500;
        cin >> n >> k;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            ans += x;
        }
        if(ans != k)
            cout <<"Bug"<<endl;
        else
            cout <<"Correct"<<endl;
    }
    return 0;
}
