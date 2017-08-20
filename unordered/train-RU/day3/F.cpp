#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,H,V;
ll l,r,u1,u,d;
 
#define F
int main()
{
#ifdef F
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin >> T>>H>>V;
    for(u = max(max(-1e8+(T+H+V)/2,-1e8+V),-1e8-H+(T+H+V)/2);u <= min(min(1e8+(T+H+V)/2,1e8+V),1e8-H+(T+H+V)/2);u++)
    {
        u1= -u;
        r = (H+T+V)/2 - u;
        d = u-V;
        l =r-H;
        if(l <= -1e8 || l >=1e8 ||r<=-1e8||r>=1e8||u<=-1e8||u>=1e8||d<=-1e8||d>=1e8)
          continue;
        if(T == (l+r+u+d) && H ==(r-l) && V ==(u-d) )
        { cout << l << ' '  << r << ' ' << u << ' ' << d;return 0;
        }
    }

}
