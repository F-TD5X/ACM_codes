#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int a[maxn],n,m;
map<int,int> mp;
bool yes;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        mp.clear();
        yes = false;
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            a[i]=(a[i-1]+a[i])%m;
            mp[a[i]]++;
            if(mp[a[i]]>1 || !a[i])
                yes = 1;
        }
        if(yes)
            cout <<"YES"<<endl;
        else
            cout <<"NO"<<endl;
    }
}
