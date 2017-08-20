#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e6;
int cas=1,n,x,li[maxn];
char com[10],s1[3],s2[3];
set<int>a,b,all;
char mer;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1010.in","r",stdin);
    //freopen("1010-3.out","w",stdout);
#endif
    while(cin >> n && n)
    {
        a.clear();
        b.clear();
        all.clear();
        mer ='C';
        printf("Case #%d:\n",cas++);
        for(int i=0;i<n;i++)
        {
            scanf("%s",com);
            if(com[1] == 'u')
            {
                scanf("%s%d",s1,&x);
                li[i] = x;
                if(s1[0]=='A')
                    a.insert(i);
                else
                    b.insert(i);
                all.insert(i);
            }
            else if(com[1] == 'o')
            {
                scanf("%s",s1);
                if(s1[0] =='A'&&a.empty())
                {
                    printf("%d\n",li[*(--all.end())]);
                    all.erase(--all.end());
                }
                else if(s1[0]=='B' && b.empty())
                {
                    printf("%d\n",li[*(--all.end())]);
                    all.erase(--all.end());
                }
                else
                {
                    if(s1[0] == 'A')
                    {
                        printf("%d\n",li[*(--a.end())]);
                        all.erase(all.find(*(--a.end())));
                        a.erase(--a.end());
                    }
                    else
                    {
                        printf("%d\n",li[*(--b.end())]);
                        all.erase(all.find(*(--b.end())));
                        b.erase(--b.end());
                    }
                }
            }
            else 
            {
                scanf("%s%s",s1,s2);
                a.clear();
                b.clear();
            }
        }
    }
    return 0;
}
