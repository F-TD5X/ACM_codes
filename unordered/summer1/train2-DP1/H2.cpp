#include <math.h>  
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
double dp[3005];  
int ans[3005],num[505],prime[3005];  
int main(){  
    double tmp;  
    int n,i,j,k,p,q,mod;  
    k=0;  
    memset(prime,0,sizeof(prime));  
    for(i=2;i<=3000;i++){  
        if(!prime[i])  
        num[k++]=i;  
        for(j=0;j<k&&num[j]*i<=3000;j++){  
            prime[num[j]*i]=1;  
            if(i%num[j]==0)  
            break;  
        }                                       //素数筛模板  
    }                                           //因为素数的lcm不用除以gcd因此,  
    while(scanf("%d%d",&n,&mod)!=EOF){          //一定首先分成素数  
        for(i=0;i<=n;i++){  
            dp[i]=0;  
            ans[i]=1;  
        }                                       //分解成素数后其实就变成一个完全背包  
        for(i=0;i<k&&num[i]<=n;i++){            //状态转移方程也很好求出,就是：  
            for(j=n;j>=num[i];j--){             //dp[j]=max(dp[j],dp[j-p]*p);  
                tmp=log(num[i]*1.0);            //但是涉及到取余，因此将dp进行取余  
                for(p=num[i],q=1;p<=j;p*=num[i],q++){  
                    if(dp[j-p]+q*tmp>dp[j]){    //所以转移方程变为:  
                        dp[j]=dp[j-p]+q*tmp;    //dp[j]=max(dp[j],dp[j-p]+q*num);  
                        ans[j]=(ans[j-p]*p)%mod;//并同时用一个数组记录真实值  
                    }  
                }  
            }  
        }  
        printf("%d\n",ans[n]);  
    }  
    return 0;  
}  
