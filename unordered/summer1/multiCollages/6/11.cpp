#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
const int mod= 1e9+7;
using namespace std;
int dp[66][16][5][5];
ll in[5];

int dfs(int p,int isup,int f1,int f2){  
    if(p<0){  
        if(f1>0&&f2>=0) return 1;  
        return 0;  
    }  
    if(dp[p][isup][f1+2][f2+2]!=-1) return dp[p][isup][f1+2][f2+2];  
    int ans=0;  
    int up[4];  
    for(int i=0;i<4;i++)
    {  
        if(isup&(1<<i)) up[i]=1;  
        else up[i]=(in[i]>>p)&1;  
    }  
    for(int i=0;i<=up[0];i++)
    {  
        for(int j=0;j<=up[1];j++)
        {  
            for(int f=0;f<=up[2];f++)
            {  
                for(int q=0;q<=up[3];q++)
                {  
                    if(f1*2+i+f-j-q<=-2)
                        continue;  
                    if(f2*2+i+q-j-f<=-2)
                        continue;  
                    int w,w1;  
                    w=2*f1+i+f-j-q;  
                    if(w>2) w=2;  
                    w1=2*f2+i+q-j-f;  
                    if(w1>2) w1=2;  
                    int no=isup;  
                    if(i!=up[0])
                        no|=1<<0;  
                    if(j!=up[1]) 
                        no|=1<<1;  
                    if(f!=up[2])
                        no|=1<<2;  
                    if(q!=up[3]) 
                        no|=1<<3;  
                    ans+=dfs(p-1,no,w,w1);  
                    ans%=mod;  
                }  
            }  
        }  
    }  
    return dp[p][isup][f1+2][f2+2]=ans;  
}  
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("11.in","r",stdin);
    //freopen("11.out","w",stdout);
#endif
    int t;  
    cin>>t;  
    while(t--)
    {  
        for(int i=0;i<4;i++) 
            scanf("%lld",&in[i]);  
        memset(dp,-1,sizeof(dp));  
        printf("%d\n",dfs(60,0,0,0));  
    }  
    return 0;
}
