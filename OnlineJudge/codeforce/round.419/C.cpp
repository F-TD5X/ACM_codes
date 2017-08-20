#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300000;

int n, m;
int a[111][111];
int ans;
vector<int> r, c;

void dorow()
{
    for(int i=0;i<n;i++)
    {
        int val = 1000;
        for(int j=0;j<m;j++) val = min(val,a[i][j]);
        ans += val;
        for (int j=0;j<m;j++) a[i][j] -= val;
        for(int k=0;k<val;k++) r.push_back(i);
    }
}

void docol()
{
    for(int i=0;i<m;i++)
    {
        int val = 1000;
        for(int j=0;j<n;j++) val = min(val,a[j][i]);
        ans += val;
        for(int j=0;j<n;j++) a[j][i] -= val;
        for(int k=0;k<val;k++) c.push_back(i);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
    cin >> n >> m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin >> a[i][j];
    if (n < m) dorow(), docol();
    else docol(), dorow();
    bool ok = 1;
    for(int  i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if (a[i][j]) ok = 0;
    if (!ok) cout << -1;
    else
    {
        cout << ans << "\n";
        for(int i=0;i<r.size();i++)
            cout << "row "<<r[i]+1<<"\n";
       	for(int i=0;i<c.size();i++)
            cout << "col "<<c[i]+1<<"\n";
    }
}
