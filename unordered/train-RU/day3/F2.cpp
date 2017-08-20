#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll T,H,V;
    ll l,r,u,d;
    cin>>T>>H>>V;
    u=-1e8-H+(H+T+V)/2;
    while(1)
    {
        r=(H+V+T)/2-u;
        d=u-V;
        l=r-H;
        if(r>=-1e8&&r<=1e8&&l>=l-1e8&&d<=1e8&&d>=-1e8&&d<=1e8)
        {
            if(T==l+u+d+r&&H==r-l)
                break;
        }
        u++;
    }
    cout<<l<<" "<<r<<" "<<u<<" "<<d<<endl;
    return 0;
}
