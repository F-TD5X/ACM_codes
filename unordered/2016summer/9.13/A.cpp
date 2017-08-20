#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int t,n,x;
char c;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    cin >> t;
    while(t--)
    {
        cin >> n;
        int ma=0,mi=0;
        while(n--)
        {
            scanf("%d%s",&x,&c);
            if(c=='-')
            {
                if(ma)
                    ma=min(ma,mi+x+25);
                else
                    ma=mi+x+25;
            }
            else
                mi+=x+25;
        }
        printf("%d\n",ma-mi);
    }
    return 0;
}

