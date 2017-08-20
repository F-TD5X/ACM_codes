#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n;
set<int> num;
vector<pair<int,int> >ans;

void init()
{
    for(int i=0;i<=sqrt(1e9);i++)
    {
        num.insert(i*i);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1080.in","r",stdin);
    //freopen("1080.out","w",stdout);
#endif
    init();
    cin >> n;
    for(auto a:num)
    {
        if(a<n/2+1)
        {
            if(num.count(n-a))
                ans.push_back(make_pair(sqrt(a),sqrt(n-a)));
        }
        else
            break;
    }
    sort(ans.begin(),ans.end());
    if(ans.size())
        for(auto a:ans)
        {
            cout << a.first<<" " << a.second << endl;
        }
    else
        puts("No Solution");
    return 0;
}
