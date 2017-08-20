#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a,b,c,a1,b1,c1,m,m1;
bool yes;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("i.in","r",stdin);
    //freopen("i.out","w",stdout);
#endif
    while(cin >>a >> b >> c>> a1>>b1>>c1)
    {
        yes=0;
        if((m=max(max(a,b),c)) == (m1=max(max(a1,b1),c1)))
        {
            if(a != m && b!= m)
            {
                if(a1 != m1 && b1 != m1)
                {
                    if((a==a1 && b == b1)||(a==b1 &&b==a1))
                        yes=1;
                }
                else if(a1 == m1)
                {
                    if((a==c1 && b==b1)||(a==b1 && b==c1))
                        yes=1;
                }
                else if(b1 == m1)
                {
                    if((a==a1 && b ==c1) || (a == c1 && b == a1))
                        yes=1;
                }
            }
            else if( a == m)
            {
                if(a1 != m1 && b1 != m1)
                {
                    if((c==a1 && b == b1)||(c==b1 &&b==a1))
                        yes=1;
                }
                else if(a1 == m1)
                {
                    if((c==c1 && b==b1)||(c==b1 && b==c1))
                        yes=1;
                }
                else if(b1 == m1)
                {
                    if((c==a1 && b ==c1) || (c == c1 && b == a1))
                        yes=1;
                }
            }
            else if(b == m)
            {
                if(a1 != m1 && b1 != m1)
                {
                    if((a==a1 && c == b1)||(a==b1 &&c==a1))
                        yes=1;
                }
                else if(a1 == m1)
                {
                    if((a==c1 && c==b1)||(a==b1 && c==c1))
                        yes=1;
                }
                else if(b1 == m1)
                {
                    if((a==a1 && c ==c1) || (a == c1 && c == a1))
                        yes=1;
                }
            }
        }
        if(yes)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
