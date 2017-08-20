#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define fi first
#define se second
map<string,vector<pair<int,int> > >ma;
string str;
int T,n,n1,l,r;
set<string>ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("M.in","r",stdin);
    //freopen("M.out","w",stdout);
#endif
    cin >>T;
    while(T--)
    {
        ans.clear();
        ma.clear();
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> str>>l>>r>>n1;
            for(int j=0;j<n1;j++)
            {
                cin >>str;
                for(int k=0;k<ma[str].size();k++)
                {
                    if(ma[str][k].fi<=l &&l<= ma[str][k].se )
                        ans.insert(str);
                    else if(ma[str][k].fi<=r && r<=ma[str][k].se)
                        ans.insert(str);
                    else if(l <= ma[str][k].fi && r>=ma[str][k].se)
                        ans.insert(str);
                }
                ma[str].push_back(make_pair(l,r));
            }
        }
        cout <<ans.size()<<endl;
        for(auto a:ans)
            cout << a<<endl;
    }
    return 0;
}
