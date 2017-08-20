#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int li[int(1e6)];
char own[int(1e6)];
int n,cas,x;
char com[10],s1[3],s2[3];
int a,b;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("1010.in","r",stdin);
    //freopen("1010-2.out","w",stdout);
#endif
    while(scanf("%d",&n)!= EOF && n)
    {
        printf("Case #%d:\n",cas++);
        fill(own,own + int(1e6),-1);
        memset(li,0,sizeof(li));
        a=b=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",com);
            if(com[1] == 'u')
            {
                scanf("%s%d",s1,&x);
                li[i]=x;
                own[i]=s1[0] == 'A'?0:1;
            }
            else if(com[1] == 'o')
            {
                scanf("%s",s1);
                if(s1[0] == 'A')
                {
                    for(int j =i;j>=0;j--)
                    {
                        if(j <= a && own[j] != -1)
                        {
                            printf("%d\n",li[j]);
                            own[j]=-1;
                            break;
                        }
                        else if(own[j] == 0)
                        {
                            printf("%d\n",li[j]);
                            own[j]=-1;
                            break;
                        }
                    }
                }
                else 
                {
                    for(int j =i;j>=0;j--)
                    {
                        if(j <= b && own[j] != -1)
                        {
                            printf("%d\n",li[j]);
                            own[j]=-1;
                            break;
                        }
                        else if(own[j] == 1)
                        {
                            printf("%d\n",li[j]);
                            own[j]=-1;
                            break;
                        }
                    }
                }
            }
            else if(com[1]=='e')
            {
                scanf("%s%s",s1,s2);
                if(s1[0] == 'A')
                    b=i,a=0;
                else
                    a=i,b=0;
            }
        }
    }
    return 0;
}
