#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
long long dp[50];

long long J(int x)
{
    if(x == 0) return 0;
    long long  ret=1;
    while(x)
    {
        ret*=x;
        x--;
    }
    return ret;
}

long long C(int n,int x)
{
    return J(n)/J(x)/J(n-x);
}

int main()
{
    dp[1]=1;dp[2]=2;dp[3]=4;
    for(int i=4;i<=20;i++)
    {
        dp[i]+=dp[i-1];
        for(int j=1;j<i-1;j++)
        {
            if(j==1||i-j-1==1)
                dp[i]+=dp[j]*dp[i-j-1]/2*C(i-1,j);
            else
                dp[i]+=dp[j]/2*dp[i-j-1]/2*C(i-1,j);
        }
    }    
    int cas; 
    cin >> T;
    while(T--)
    {
        cin >> cas >>n;
        cout << cas <<" "<< dp[n] << endl;
    }

}
