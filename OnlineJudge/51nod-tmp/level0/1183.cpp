#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int Maxn=1111;
int vis[Maxn];  
int w[Maxn];  
int sum[Maxn];  
int head[Maxn];  
int num;  
int n,m;  
int dis[Maxn][Maxn];  
int main()  
{  
    int i,j;  
    char s1[Maxn];  
    char s2[Maxn];  
    while(gets(s1))  
    {  
        gets(s2);  
        int l1=strlen(s1);  
        int l2=strlen(s2);  
        for(i=0; i<1002; i++)  
            dis[0][i]=i;  
        for(i=0; i<1002; i++)  
            dis[i][0]=i;  
        for(i=1; i<=l1; i++)  
            for(j=1; j<=l2; j++)  
            {  
                if(s1[i-1]==s2[j-1])  
                    dis[i][j]=dis[i-1][j-1];  
                else  
                    dis[i][j]=min(dis[i-1][j-1],min(dis[i-1][j],dis[i][j-1]))+1;  
            }  
        cout<<dis[l1][l2]<<endl;;  
    }  
    return 0;  
}  
