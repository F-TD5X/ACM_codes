#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
multiset<string> str;
map<string,int> mp;
string s,t;
int ans=0,n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1095.in","r",stdin);
    //freopen("1095.out","w",stdout);
#endif
    cin >> n;
    str.clear();
    mp.clear();
    for(int i=0;i<n;i++)
    {
        cin >> s;
        t=s;
        sort(s.begin(),s.end());
        mp[t]++;
        str.insert(s);
    }
    int q;
    cin >> q;
    while(q--)
    {
        cin >> s;
        t=s;
        sort(s.begin(),s.end());
        cout << str.count(s)-mp[t]<<endl;
    }
    return 0;
}
