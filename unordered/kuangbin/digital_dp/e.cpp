#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int c[33][33];
int a[35];
void init()
{
    for(int i=0;i<=32;i++)
        for(int j=0;j<=i;j++)
            if(!j || i==j)
                c[i][j]=1;
            else
                c[i][j]=c[i-1][j-1]+c[i-1][j];
}

int solve(int n)
{
    a[0]=0;
    int sum=0;
    while(n)
    {
        a[++a[0]]=n%2;
        n/=2;
    }
    for(int i=1;i<a[0]-1;i++)
        for(int j=i/2+1;j<=i;j++)
            sum+=c[i][j];
    int z=0;
    for(int i = a[0]-1;i>=1;i--)
        if(a[i])
            for(int j=(a[0]+1)/2-z-1;j<=i-1;j++)
                sum+=c[i-1][j];
        else
            z++;
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("e.in","r",stdin);
    //freopen("e.out","w",stdout);
#endif
    init();
    int a,b;
    cin >> a >> b;
    cout << solve(b+1)-solve(a) << endl;
    return 0;
}
