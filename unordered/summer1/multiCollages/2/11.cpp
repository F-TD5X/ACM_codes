#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
using namespace std;
int T;
const int maxn =  1e5+7;
map<int,int>li;
vector<pair<int,int> >p;
int x,y,n,m,len;
bool yes;

int cmp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        li.clear();
        yes =false;
        scanf("%d%d",&n,&m);
        p.clear();
        for(int i =0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            p.push_back(mp(x,y));
        }
        sort(p.begin(),p.end(),cmp);
        for(int i =0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                len = fabs(p[i].first - p[j].first)+fabs(p[i].second-p[j].second);
                if(len > 0)
                {
                    li[len]++;
                    if(li[len]>=2)
                    {
                        yes = true;
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
