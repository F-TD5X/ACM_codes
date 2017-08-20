#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int pow(int x,int y)
{
    int ret=1;
    for(int i=0;i<y;i++)
        ret*=x;
    return ret;
}
bool isis(int x)
{
    int p=x,n=0;
    int l[10],cnt=0;
    while(p)
    {
        l[cnt++]=p%10;
        p/=10;
    }
    for(int i=0;i<cnt;i++)
    {
        n+=pow(l[i],cnt);
    }
    if(n==x)
        return 1;
    else
        return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1015.in","r",stdin);
    //freopen("1015.out","w",stdout);
#endif
    int n;
    cin >> n;
    while(1)
    {
        if(isis(n))
        {
            cout << n << endl;
            return 0;
        }
        else
            n++;
    }
    return 0;
}
