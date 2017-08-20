#include<bits/stdc++.h>
using namespace std;
int ans;
const int maxn=1e5+10;
int p[maxn],a[maxn],T,x,y,z,n ;
set<int >s[maxn];
int main()
{
    cin >>T;
    for(int cas=1;cas<=T;cas++)
    {
        cin >> n >> x>>y;
        for(int i=0;i<n;i++)
            cin >> p[i] >> a[i];
        ans = (y-x)/7;
        for(int i = x%7==0?x/7:x/7+1;i<y/7;i++)
        {
        }
        cout << ans << endl;
    }
}
