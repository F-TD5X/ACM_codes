#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2e5+10;
int mex[maxn],a[maxn],pos[maxn],last;
long long t,ans;

int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        ans = t = 0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        memset(mex,0,sizeof(mex));
        memset(pos,0,sizeof(pos));
        for(int i=1;i<=n;i++)
        {
            if(a[i] < n)
            {
                last = pos[a[i]];
                pos[a[i]]=i;
                for(int j=a[i];j<n;j++)
                {
                    if(j)
                        mex[j] = min(mex[j-1],pos[j]);
                    else
                        mex[j]=i;
                    if(mex[j] > last)
                        t+= mex[j]-last;
                    else
                        break;
                }
                cout << endl;
            }
            ans +=t;
        }
        printf("%I64d\n",ans); 
    }
}
