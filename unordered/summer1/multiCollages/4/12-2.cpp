#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int tree[maxn],T,n,x;
int a[maxn],ans[maxn];
vector<pair<int,int> >v;
int lowbit(int x)
{
    return x&(-x);
}

void update(int x)
{
    while(x<maxn)
    {
        tree[x]++;
        x+=lowbit(x);
    }
}

int query(int x)
{
    int ret=0;
    while(x)
    {
        ret+=tree[x];
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
    cin >>T;
    for(int cas=1;cas<=T;cas++)
    {
        cin >>n;
        memset(tree,0,sizeof(tree));
        v.clear();
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            v.push_back(make_pair(a[i],i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            ans[i+1]=max(v[i].second,v[i].second+query(maxn-1)-query(v[i].second)) - min(v[i].first,v[i].second);
            update(v[i].second);
        }
        cout <<"Case #"<<cas<<":";
        for(int i=1;i<=n;i++)
        {
            cout <<" " << ans[i];
        }
        cout << endl;
    }
}
