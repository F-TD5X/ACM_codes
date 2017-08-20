#include<iostream>
#include<iomanip>
using namespace std;
const int N=1e5+7;
int sz[N],p[N];
double dp[N];
int main()
{
    int n;
    cin >> n;
    for(int i =2;i<=n;i++)
        cin >> p[i];
    for(int i =1;i<=n;i++)
        sz[i]=1;
    for(int i =n;i>=2;i--)
        sz[p[i]]+=sz[i];
    dp[1]=1;
    for(int i =2;i<=n;i++)
        dp[i]=dp[p[i]]+1+(sz[p[i]]-sz[i]-1)/2.0;
    for(int i = 1;i<=n;i++)
        cout <<fixed << setprecision(1) <<dp[i] << " ";
}
