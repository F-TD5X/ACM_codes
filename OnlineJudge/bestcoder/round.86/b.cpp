#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int T;
int n;
int a[100010];
int ma,ma1;
ll ans;
int main()
{
    cin >>T;
    while(T--)
    {
        ans =0;
        cin >> n;
        cin >> a[0] >> a[1];
        ma1 = ma = fabs(a[0]-a[1]);
        for(int i=2;i<n;i++)
        {
            cin >> a[i];
            if(ma < fabs(a[i]-a[i-1]))
            {
                ma1 = ma;
                ma = fabs(a[i]-a[i-1]);
            }
        }
        if(ma == fabs(a[0]-a[1]))
            ans+=ma1;
        else
            ans+=ma;
        if(ma == fabs(a[n-1]-a[n-2]))
            ans += ma1;
        else
            ans +=ma;
        for(int i=1;i<n-1;i++)
        {
            if(fabs(a[i+1]-a[i-1])>ma)
                ans +=fabs(a[i+1]-a[i-1]);
            else
                ans +=ma;
        }
        cout << ans << endl;
    }
    return 0;
}
