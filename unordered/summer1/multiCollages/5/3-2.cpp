#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,loc[maxn],cnt;
ll ans,sum,a[maxn];
int main()
{
    freopen("1003.in","r",stdin);
    while(cin >> n)
    {
        ans = n;
        sum = 0;
        cnt =0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i] < 0) loc[cnt++] = i;
        }
        for(int i=cnt-1;i>=0;i--)
        {
            
        }
        cout << ans << endl;
    }
}
