#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n;
int m1[111][111],m2[111][111],m3[111][111];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1137.in","r",stdin);
    //freopen("1137.out","w",stdout);
#endif
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> m1[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> m2[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int c=0;
            for(int k=0;k<n;k++)
                c+=m1[i][k]*m2[k][j];
            m3[i][j]=c;
        }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << m3[i][j] <<" ";
        cout <<endl;
    }
    return 0;
}
