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

struct Node
{
    string l,f;
}name[111];
int n;
bool cmp(const Node &a,const Node &b)
{
    if(a.l == b.l)
        return a.f <b.f;
    return a.l<b.l;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
    while(cin >> n)
    {
        for(int i=0;i<n;i++)
        {
            cin >> name[i].f >> name[i].l;
        }
        sort(name,name+n,cmp);
        for(int i=0;i<n;i++)
            cout << name[i].f <<" " << name[i].l << endl;
    }
    return 0;
}
