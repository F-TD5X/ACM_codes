#include<bits/stdc++.h>
using namespace std;
double a,v1,v2,ans;
int main()
{
    freopen("1010.in","r",stdin);
    freopen("1010","w",stdout);
    while(cin >> a>> v1>> v2)
    {
        if(a == 0)
        {
            cout <<"0.0000000000"<<endl;
            continue;
        }
        if(v1 <=v2)
        {
            cout <<"Infinity" << endl;
            continue;
        }
        ans = (v1*a)/(v1*v1-v2*v2);
        cout << fixed << setprecision(10)<<ans <<endl;
    }
}
