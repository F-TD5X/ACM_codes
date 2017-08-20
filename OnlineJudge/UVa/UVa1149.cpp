#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int s,n;
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa1149.in","r",stdin);
    //freopen("UVa1149.out","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
        cin >>n>>s;
        ans=0;
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        for(int r=n-1,l=0;r>=l;)
        {
            if(r==l)
            {
                ans++;
                break;
            }
            else if(a[r]+a[l]<=s)
            {
                ans++;
                r--;l++;
            }
            else
            {
                ans++;
                r--;
            }
        }
        if(t==1)
            cout << ans <<endl;
        else
            cout << ans <<endl<<endl;
    }
    return 0;
}
