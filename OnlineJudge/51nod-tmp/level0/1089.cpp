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
string s;
int ans;

int M(string &s)
{
    int mx=0,id=0,p[999999]={0};
    for(int i=1;i<=s.size();i++)
    {
        if(mx>1)
            p[i]=(p[2*id-i])<(mx-i)?p[2*id-i]:(mx-i);
        else
            p[i]=i;
        while(s[i-p[i]]==s[i+p[i]])
            p[i]++;
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
    }
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans = max(ans,p[i]);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1089.in","r",stdin);
    //freopen("1089.out","w",stdout);
#endif
    cin >> s;
    string s0="$#";
    for(int i=0;i<s.size();i++)
    {
        s0+=s[i];
        s0+='#';
    }
    cout << M(s0)-1<<endl;
    return 0;
}
