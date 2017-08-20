#include<bits/stdc++.h>
#define cle(n) memset(n,0,sizeof(n))
using namespace std;
typedef long long ll;
const ll inf =1e9;
const int maxn = 200010;
const int mod = 1000000007;

int T,n,m;
int a[10];
int main()
{
    scanf("%d",&T);
    //while(~scanf("%d%d",&n,&m))
    while(T--)
    {
       cin>>n;
       int ans=0;
       while(n--)
       {
          // cle(a);
            for(int i=1;i<=7;i++)
                cin>>a[i];
            int temp=0;
            int flag=0;
            for(int i=1;i<=6;i++)
                {
                    a[i]-=a[7];
                    if(a[i]<0)flag=1;
                }
            a[1]-=a[4];a[1]-=a[6];
            a[2]-=a[4];a[2]-=a[5];
            a[3]-=a[5];a[3]-=a[6];
            int sum=0;
            for(int i=1;i<=7;i++)
            {
                if(a[i]<0)flag=1;
                sum+=a[i];
            }
           if(flag)continue;
           else
                ans=max(sum,ans);
       }
       cout<<ans<<endl;
    }
    return 0;
}
