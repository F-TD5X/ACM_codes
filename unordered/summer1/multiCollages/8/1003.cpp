#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,mask;
int vi[1<<18],res[1<<18];
char ma[20][20];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(vi,0,sizeof(vi));
        mask = (1<<n)-1;
        for(int i=0;i<n;i++)
            scanf("%s",&ma[i]);
        for(int i=1;i<=mask;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1)
                {
                    for(int k = 0;k<n;k++)
                    {
                        if((i>>k)&1 && ma[i][j] == '1')
                        {
                            vi[i] =1;
                            break;
                        }
                    }
                    if(vi[i])
                        break;
                }
            }
        }
        memset(res,0x3f,sizeof(res));
        res[0] = 0;
        for(int i =1;i<=mask;i++)
        {
            for(int j=i;j;j=(j-1)&i)
                if(!vi[j])
                {
                    res[i] = min(res[i],res[i^j]+1);
                }
        }
        int proc=1,ans=0;
        for(int i=1;i<=mask;i++)
            ans =(ans+ res[i]*(proc*=233))%(1<<32);
        cout << ans << endl;
    }
    return 0;
}
