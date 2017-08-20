#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
set<int>s;
vector<int>v,v2;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1004.in","r",stdin);
    //freopen("1004.out","w",stdout);
#endif
    int t,n;
    //cin >> t;
    while(cin >> n)
    {
        v2.clear();
        s.clear();
        v.clear();
        //scanf("%d",&n);
        int num = 3*(n+6);
        while(v.size() < n)
        {
            for(int i=num;i>0;i--)
            {
                if(!s.count(i))
                {
                    s.insert(i);
                    v.push_back(i);
                }
                if(v.size() >=n)
                    break;
            }
        }
        for(int i=0;i<v.size();i++)
            cout << v[i] <<" ";
        cout << endl;
    }
    return 0;
}
