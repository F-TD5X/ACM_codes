#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int t,n,x,y,flag;
int sum;
pair<int,int> dt[1011];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1005.in","r",stdin);
    //freopen("1005.out","w",stdout);
#endif
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        sum =0;
        flag =0;
        cin >>n;
        for(int i=1;i<=n;i++)
        {
            cin >> x;
            sum +=x;
            dt[i].first=x;
            dt[i].second = i;
        }
        sort(dt+1,dt+1+n);
        for(int i=1;i<=n;i++)
            if(dt[i].first >=i)
            {
                flag=1;break;
            }
        if(flag)
            printf("Case #%d: No\n",i);
        else
        {
            printf("Case #%d: Yes\n",i);
            printf("%d\n",sum);
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=dt[i].first;j++)
                    printf("%d %d\n",dt[i].second,dt[j].second);
            }
        }
    }

    return 0;
}
