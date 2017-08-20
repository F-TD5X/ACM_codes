#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

set<int> ans;
vector<string>t;
string str;

bool check(int l,int r)
{
    if(r-l==1)
        return true;
    int i=l,j=r-1;
    while(i<=j)
    {
        if(str[i++]!=str[j--])
            return false;
    }
    return 1;
}

void dfs(int l,int r,vector<string> t,set<int> &ret)
{
    if(r-l==0)
    {
        ret.insert(t.size());
        return;
    }
    for(int i=l+1;i<=r;i++)
    {
        if(check(l,i))
        {
            t.push_back(" ");
            dfs(i,r,t,ret);
            t.pop_back();
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
    int T,q,n;
    cin >> T;
    for(int cas=1;cas<=T;cas++)
    {
        bool yes=0;
        printf("Case #%d:\n",cas);
        ans.clear();
        t.clear();
        cin >> str;
        dfs(0,str.size(),t,ans);
        cin >> q;
        for(int i=0;i<q;i++)
        {
            yes=0;
            cin >> n;
            if(ans.count(n)!=0)
                puts("yes");
            else
                puts("no");
        }
    }
    return 0;
}
