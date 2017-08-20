#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
typedef long long ll;
int n,a[maxn],loc[maxn];
int sum;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int ans=n,cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<0)loc[cnt++]=i;
        }
        if(cnt==0)
        {
            printf("%d\n",n);
            continue;
        }
        cnt--;
        while(cnt>=0)
        {
            int i=loc[cnt]-1;
            ll sum=a[loc[cnt]];
            while(sum<0)
            {
                sum+=a[i];
                if(a[i]<0)cnt--;
                ans--;
                i--;
            }
            cnt--;
        }
        printf("%d\n",ans);
    }
    return 0;
}

