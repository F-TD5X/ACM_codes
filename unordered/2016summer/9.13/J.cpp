#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e5+10;
map<string,map<string,int>> mp;
int n,k,c;
string str,str1,str2;
set<string> ans;
map<string,int> vi;
map<string,vecotr<string>> base;


int dfs(string s)
{
    if(vi[string])
        return 0;
    
}



int main()
{
#ifndef ONLINE_JUDGE
    //freopen("J.in","r",stdin);
    //freopen("J.out","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
    cin >> n >> k;
    ans.clear();
    for(int i=0;i<n;i++)
    {
        cin >> str >> c;
        if(c==0)
            mp[str][str]=1;
        else
            for(int j=0;j<n;j++)
            {
                cin >>str1;
                mp[str][str1]=1;
                base[str].push_back(str1);
            }
    }
    for(int i=0;i<k;i++)
    {
        cin >>str;
    }
    }
    return 0;
}
