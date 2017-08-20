#include<bits/stdc++.h>
using namespace std;
#define A
double h,w,s,p;
int main()
{
#ifdef A
    freopen("alex.in","r",stdin);
    freopen("alex.out","w",stdout);
#endif

    while(cin >> h>>w)
    {
        if(h>w)
        {
            double t = h;
            h = w;
            w = t;
        }
        p = w/h;
        if(p >= 3)
        {
            s=  h;
        }
        else if(p>=1.5)
        {
            s = w/3;
        }
        else
        {
            s = h/2;
        }
        cout <<fixed<<setprecision(3)<< s <<endl;
    }
}
