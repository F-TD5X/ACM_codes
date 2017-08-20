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
        }                                       //����ɸģ��  
    }                                           //��Ϊ������lcm���ó���gcd���,  
    while(scanf("%d%d",&n,&mod)!=EOF){          //һ�����ȷֳ�����  
        for(i=0;i<=n;i++){  
            dp[i]=0;  
            ans[i]=1;  
        }                                       //�ֽ����������ʵ�ͱ��һ����ȫ����  
        for(i=0;i<k&&num[i]<=n;i++){            //״̬ת�Ʒ���Ҳ�ܺ����,���ǣ�  
            for(j=n;j>=num[i];j--){             //dp[j]=max(dp[j],dp[j-p]*p);  
                tmp=log(num[i]*1.0);            //�����漰��ȡ�࣬��˽�dp����ȡ��  
                for(p=num[i],q=1;p<=j;p*=num[i],q++){  
                    if(dp[j-p]+q*tmp>dp[j]){    //����ת�Ʒ��̱�Ϊ:  
                        dp[j]=dp[j-p]+q*tmp;    //dp[j]=max(dp[j],dp[j-p]+q*num);  
                        ans[j]=(ans[j-p]*p)%mod;//��ͬʱ��һ�������¼��ʵֵ  
                    }  
                }  
            }  
        }  
        printf("%d\n",ans[n]);  
    }  
    return 0;  
}  
