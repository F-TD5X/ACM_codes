#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<long double ,long double>mp;
long double num,sum;
long double ave;
char c;
int n;
long double t;

int main()
{
    freopen("cars.in","r",stdin);
    freopen("cars.out","w",stdout);
    while(cin>>n)
    {
        queue<double>q;
        num=0;
        sum=0;
        mp.clear();
        for(int i=0;i<n;i++)
        {
            cin>>c;
            if(c=='+')
            {
                cin>>t;
                num+=1;
                sum+=t;
                q.push(t);
                if(!mp.count(t))
                  mp[t]=0;
                mp[t]+=1;
            }
            else if(c=='-')
            {
                num--;
                sum-=q.front();
                mp[q.front()]--;
                q.pop();
            }
            else if(c=='?')
            {
                ave=sum/num;
                if(mp.count(ave))
                  cout<<mp[ave]<<endl;
                else
                  cout<<0<<endl;
            }
        }
    }
    return 0;
}
