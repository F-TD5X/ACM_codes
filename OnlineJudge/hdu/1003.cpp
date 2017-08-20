#include<bits/stdc++.h>
using namespace std;
int ca,n,ans,beg,e,T,w;
int t,p;
int main()
{
    cin >> T;ca = 0;
    for(int j =1;j<=T;j++)
    {
        cin >> n;
        beg = 1;e =1;
        w = 1;
        ans =-999999999;t = 1;
        p = 0;
        printf("Case %d:\n",j);
        for(int i=1;i<=n;i++)
        {
            cin >> w;
            p+=w;
            //printf("p:%d , ans:%d ,beg: %d,e: %d\n",p,ans,beg,e);
            if(p>ans)
            {
                ans = p;
                beg = t;e = i;
            }
            if(p < 0)
            {
                p= 0;
                t = i+1;
            }
        }
        cout << ans <<" "<<beg <<" "<<e <<endl;
        if(j!=T)cout <<endl;
    }
}
