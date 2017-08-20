#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a,b;
int cnt;
char s[100010];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
    int t,n;
    char c,c1,c2;
    cin >> t;
    bool yes=0;
    int l,e;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        l=e=0;
        if(n%2==1)
            yes=0;
        else
        {
            for(int i=0;i<n;i++)
            {
                if(s[i] == '(')
                    l++;
                else if(s[i] == ')')
                {
                    if(l == 0)
                    {e++;yes=0;}
                    else
                        l--;
                }
            }
            if(e <=2)
                yes=1;
            if(l!=e)
                yes=0;
            if(e ==0 && n ==2)
                yes=0;
        }
        if(yes)
            cout <<"Yes"<<endl;
        else
            cout <<"No"<<endl;
    }
    return 0;
}
