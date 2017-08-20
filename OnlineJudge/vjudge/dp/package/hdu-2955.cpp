#include<iostream>  
#include<cstdio>  
#include<cstring>
using namespace std;  
#define max(a,b) (a)>(b)?(a):(b)  
double dp[10010];  
struct node  
{  
    int v;  
    double p;  
}bag[10010];  
int main()  
{  
    int T,i,j,n,sum;  
    double p;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%lf%d",&p,&n);  
        sum=0;  
        for(i=0;i<n;i++)  
        {  
            scanf("%d%lf",&bag[i].v,&bag[i].p);  
            sum+=bag[i].v;  
        }  
        memset(dp,0,sizeof(dp));  
        dp[0]=1;  
        for(i=0;i<n;i++)  
            for(j=sum;j>=bag[i].v;j--)  
                dp[j]=max(dp[j],dp[j-bag[i].v]*(1-bag[i].p));  
            for(i=sum;i>=0;i--)  
            {  
                if(dp[i]>1-p)  
                {  
                    printf("%d\n",i); break;  
                }     
            }  
    }  
    return 0;  
}  
