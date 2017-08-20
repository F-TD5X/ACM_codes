#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[1005],sum[1005];

int main()
{
    a[0]=0,a[1]=3,a[2]=3,a[3]=5,a[4]=4,a[5]=4,a[6]=3,a[7]=5,a[8]=5,a[9]=4,a[10]=3;
a[11]=6,a[12]=6,a[13]=8,a[14]=8,a[15]=7,a[16]=7,a[17]=9,a[18]=8,a[19]=8,a[20]=6;
a[30]=6,a[40]=5,a[50]=5,a[60]=5,a[70]=7,a[80]=6,a[90]=6;
    for(int i=21;i<100;i++)
    {
        a[i]=a[i/10*10]+a[i%10];
    }
    for(int i=100;i<1000;i+=100)
        a[i]=a[i/100]+7;
    for(int i=101;i<1000;i++)
    {
        if(i%100!=0)
        {
            a[i]=a[i/100*100]+a[i%100]+3;
        }
    }
    a[1000]=11;
    for(int i=1;i<=1000;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int T,n;
    cin >>T;
    while(T--)
    {
        cin >> n;
        cout << sum[n] << endl;
    }
}

