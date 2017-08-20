#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n;
string s[1005];
char ans[10000];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa1610.in","r",stdin);
    //freopen("UVa1610.out","w",stdout);
#endif
    while(cin >> n && n)
    {
        for(int i=0;i<n;i++)
            cin >> s[i];
        sort(s,s+n);
        string t1=s[n/2-1],t2=s[n/2];
        for(int i=0;i<min(t1.size(),t2.size());i++)
        {
            if(t1[i]==t2[i])
                cout <<t1[i];
            else if(char(t1[i]+1) < t2[i])
            {
                cout <<char(t1[i]+1);
                break;
            }
            else
            {
                cout <<t1[i]<<char(t1[i+1]+1);
                break;
            }
        }
        cout << endl;
    }
    return 0;
}
