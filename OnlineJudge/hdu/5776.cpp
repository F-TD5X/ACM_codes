#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const int maxn=1e5+10;
int T,n,m,a[maxn],psum[maxn];
bool yes;
map<int,int>mp;

int main()
{
    cin >> T;
    while(T--)
    {
        memset(psum,0,sizeof(psum));
        scanf("%d%d",&n,&m);
        yes=0;
        mp.clear();
        if(n > m)
        {
            cout <<"YES"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            psum[i] = psum[i-1]+a[i];
            mp[psum[i]%m]++;
            if(mp[psum[i]%m]>1 && psum[i]%m !=0)
                yes= 1;
        }
        if(yes)
            cout << "YES" << endl;
        else
            cout << "NO"<<endl;
    }
}
