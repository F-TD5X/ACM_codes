#include<bits/stdc++.h>
using namespace std;
int ans,num0,a[int(1e6+10)];
int T;
int n,x,pos;
int main()
{
    cin >>T;
    for(int cas=1;cas <=T;cas++)
    {
        ans = 0;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >>x;
            if(x==0)
                num0++;
            else
            {
                x-=num0;
                pos = lower_bound(a,a+i,x) - a;
                a[pos]=x;
                ans = max(ans,pos);
            }
        }
        cout << "Case #"<<cas<<": "<<ans+num0<<endl;
    }
}
