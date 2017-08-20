#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include<string>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
map<string,string>mp;
string a;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
    int n,m;
    cin >> n >> m;
    string s1,s2;
    for(int i=0;i<m;i++)
    {
        cin >> s1>>s2;
        if(s1.size()>s2.size())
        {
            mp[s1]=s2;
        }
        else
            mp[s1]=s1;
    }
    for(int i=0;i<n;i++)
    {
        cin >> s1;
        cout << mp[s1] << " ";
    }
    cout << endl;
    return 0;
}
