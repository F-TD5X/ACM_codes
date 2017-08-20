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
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    int n;
    string s[100000];
    cin >> n;
    bool yes=true;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<s[i].size() && yes;j++)
        {
            if(s[i][j] == 'O'&& s[i][j+1]=='O')
            {
                yes=false;
                s[i][j]='+';
                s[i][j+1]='+';
            }
        }
    }
    if(yes)
        cout << "NO" << endl;
    else
    {
        cout <<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            cout << s[i] << endl;
        }}
    return 0;
}
