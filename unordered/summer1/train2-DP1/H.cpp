#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=3000;
int prime[6000],S,M,num_p,ans[6000];
double dp[6000];
bool isprime[maxn];
void init()
{
    memset(isprime,0,sizeof(isprime));  
    for(int i=2;i<=3000;i++)
    {  
        if(!isprime[i])  
            prime[num_p++]=i;  
        for(int j=0;j<num_p&&prime[j]*i<=3000;j++)
        {  
            isprime[prime[j]*i]=1;  
            if(i%prime[j]==0)  
                break;  
        }
    }     
}

int main()
{
    double tmp;
    init();
    while(cin >>S >> M)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=S;i++) ans[i]=1;
        for(int i=0;i<num_p&&prime[i]<=S;i++)
        { 
            for(int j=S;j>=prime[i];j--)
            {
                tmp=log(prime[i]*1.0); 
                for(int p=prime[i],q=1;p<=j;p*=prime[i],q++)
                {  
                    if(dp[j-p]+q*tmp>dp[j])
                    {
                        dp[j]=dp[j-p]+q*tmp;
                        ans[j]=(ans[j-p]*p)%M;
                    }  
                }  
            }  
        }  
        printf("%d\n",ans[S]);  
    }
}
