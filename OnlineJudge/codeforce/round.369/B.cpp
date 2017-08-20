#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll ma[555][555];
int n;
int ans;
ll li[4];
int x,y;
int main()    
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
    cin >> n;
    bool yes=false;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin >> ma[i][j];
            ma[i][n] +=ma[i][j];
            if(ma[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    if(x == 0)
    {
        ma[x][y] = ma[1][n]-ma[x][n];
        ma[x][n] = ma[1][n];
    }
    else
    {
        ma[x][y] = ma[x-1][n]-ma[x][n];
        ma[x][n] = ma[x-1][n];
    }
    for(int i=0;i<n;i++)
    {
        li[0]+=ma[i][i];
        li[1]+=ma[i][n-i-1];
        for(int j=0;j<n;j++)
            ma[n][i]+=ma[j][i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(ma[i][n]!=ma[i+1][n] || ma[n][i] != ma[n][i+1] || li[0] != ma[i][n] || li[1]!=ma[i][n] || ma[i][n]!=ma[n][i])
        {
            yes = true;
            break;
        }
    }
    if(n==1)
        puts("1");
    else if(yes || ma[x][y]==0)
        puts("-1");
    else if(ma[x][y]==0)
        puts("1");
    else if(ma[x][y]<0)
        puts("-1");
    else
        cout << ma[x][y]<<endl;
    return 0;
}
