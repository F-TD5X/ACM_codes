#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

set<string>ans;
char S[11],s[11];
int vi[11],len;

int dfs(int rt)
{
    if(rt ==len+1)
    {
        string str=s;
        ans.insert(str);
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            if(!vi[i])
            {
                vi[i]=1;
                s[rt-1]=S[i];
                dfs(rt+1);
                vi[i]=0;
            }
        }
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1384.in","r",stdin);
    //freopen("1384.out","w",stdout);
#endif
    scanf("%s",S);
    len=strlen(S);
    dfs(1);
    for(auto a:ans)
        cout << a << endl;

    return 0;
}
