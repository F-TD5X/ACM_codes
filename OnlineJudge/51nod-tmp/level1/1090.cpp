#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001];
int main()
{
    int n,i,j,k,flag,ke;
    while(scanf("%d",&n)!=EOF)
    {
        flag=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=0;i<n;i++)
        {
            j=i+1;k=n-1;ke=a[i];
            while(j<k)
            {
                if(a[j]+a[k]==-ke)
                {
                    flag=1;
                    printf("%d %d %d\n",a[i],a[j],a[k]);
                    j++;
                    k--;
                    continue;
                }
                else if(a[j]+a[k]<-ke)
                {
                    j++;
                }
                else k--;
            }
        }
        if(!flag) printf("No Solution\n");
    }
    return 0;
}

