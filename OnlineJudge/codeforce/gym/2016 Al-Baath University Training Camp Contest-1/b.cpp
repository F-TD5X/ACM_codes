#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
string a,b;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
#endif
    bool yes;
    int t;
    cin >> t;
    while(t--)
    {
        cin >>a>>b;
        yes=1;
        if(a.size()!=b.size())
        {
            cout <<"No"<<endl;
            continue;
        }
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='P'||a[i]=='p'||a[i]=='b'||a[i]=='B')
                a[i]='b';
            if()
        }
        if(yes)
            cout <<"Yes"<<endl;
        else
            cout <<"No"<<endl;
    }
    return 0;
}
