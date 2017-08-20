#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int x,q;
int n;
int pos[1000];
char c;
string str,ss;
char solve(string s)
{
    int l=1,r=str.size();
    for(int i=0;i<n;i++)
    {
        if(s[pos[i]-1]=='1')
            l=(l+r)/2+1;
        else
            r=(l+r)/2;
    }
    if(l==r)
        return str[l-1];
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa712.in","r",stdin);
    //freopen("UVa712.out","w",stdout);
#endif
    int cas=1;
    while(cin >> n && n)
    {   
        printf("S-Tree #%d:\n",cas++);
        for(int i=0;i<n;i++)
        {
            cin >> c >> x;
            pos[i]=x;
        }
        cin >>str;
        cin >> q;
        while(q--)
        {
            cin >>ss;
            cout << solve(ss);
        }
        cout <<endl<<endl;
    }
    return 0;
}
