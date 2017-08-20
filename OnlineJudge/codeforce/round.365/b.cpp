#include<bits/stdc++.h>
using namespace std;
const int maxn= 1e6+10;
int a[maxn],b[maxn],n,k,u[maxn];
long long sum=0;
long long ans=0;
int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {

        cin >> a[i];
        sum +=a[i];
    }
    for(int i=0;i<k;i++)
    {
        cin >> b[i];
        sum -= a[b[i]];
        ans += a[b[i]]*sum;
        u[b[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        int en = i+1;
        if(en > n)en=1;
        if(u[i]==0 && u[en]==0)
            ans += a[i]*a[en];
    }
    cout << ans << endl;
}
