#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e6+19;

set<int> ans;
int dp[maxn];
string str;

bool check(int l,int r)
{
    if(r-l==1)
        return 1;
    while(l<r)
    {
        if(str[l++]!=str[r--])
            return 0;
    }
    return 1;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H1.in","r",stdin);
    //freopen("H1.out","w",stdout);
#endif
    int T,q,n;
    cin >>T;
    for(int cas=1;cas<=T;cas++)
    {
        cin >>str;
        for(int i=0;i<str.size();i++)
        {

        }
    }
    return 0;
}
