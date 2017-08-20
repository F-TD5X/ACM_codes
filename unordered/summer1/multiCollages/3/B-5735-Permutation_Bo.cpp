#include<bits/stdc++.h>
using namespace std;
const int maxn=1111;
int c[maxn];
double v,ans,sum;
int main()
{
    int T,n;
    while(cin >> n)
    {
        sum = 0;
        for(int i=0;i<n;i++)
            cin >> c[i];
        if(n ==1)
            printf("%.6f\n",(double)c[0]);
        else
        {
            sum+=1.0*c[0]/2;
            sum += 1.0*c[n-1]/2;
            for(int i =1;i<n-1;i++)
                sum+=1.0*c[i]/3;
            printf("%.6f\n",sum);
        }
    }
    return 0;
}
