#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > ma;
map<int,int> li;

int cmp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first<p2.first;
}

int main()
{
    int T,n,m,x,y,len;
    bool yes;
    scanf("%d",&T);
    while(T--)
    {
        ma.clear();
        li.clear();
        yes =0;
        scanf("%d%d",&n,&m);
        for(int i =0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            ma.push_back(make_pair(x,y));
        }
        sort(ma.begin(),ma.end(),cmp);
        for(int i=0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                len = fabs(ma[i].first - ma[j].first)+fabs(ma[i].second-ma[j].second);
                if(len >0)
                    li[len]++;
                if(li[len]>1)
                {
                    yes = 1;
                    goto TO;
                }
            }
        }
TO:
        if(yes)
            cout <<"YES"<<endl;
        else
            cout <<"NO"<<endl;
    }
}
