#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
set<string> v[111];
struct Time
{
    int t,id;
}con1[111],con2[111];

string name,ss;
int T,n,n1;
set<string > ans;

int cmp(Time a,Time b)
{
    return a.t<b.t;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
    cin >>T;
    while(T--)
    {
        ans.clear();
        cin >> n;
        for(int i=0;i<n;i++)
            v[i].clear();
        for(int i=0;i<n;i++)
        {
            cin >> name >> con1[i].t>>con2[i].t >> n1;
            con1[i].id=con2[i].id=i;
            for(int j=0;j<n1;j++){
                cin >> ss;
                v[i].insert(ss);
            }
        }
        sort(con1,con1+n,cmp);
        sort(con2,con2+n,cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n && con2[j].t >= con1[i].t;j++)
            {
                if(con2[j].id!=con1[i].id)
                {
                    for(auto a:v[con1[i].id])
                    {
                        if(v[con2[j].id].count(a))
                            ans.insert(a);
                    }
                }
            }
        }
        cout <<ans.size()<<endl;
        for(auto a:ans)
            cout << a << endl;
    }
    return 0;
}
