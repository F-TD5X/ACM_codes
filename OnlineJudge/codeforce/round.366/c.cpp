#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int>P;

const int N=3e5+7;
int n,q,x,y,ed,v[N];
vector<int>Q[N];
set<int>cnt;
set<int>::iterator it;

int main()
{
    scanf("%d%d",&n,&q);
    while(q--)
    {
        scanf("%d%d",&x,&y);
        if(x==1)
        {
            Q[y].pb(++ed);
            cnt.insert(ed);
        }
        else if(x==2)
        {
            int sz=Q[y].size();
            for(int j=0;j<sz;j++)
                cnt.erase(Q[y][j]);
            Q[y].clear();
        }
        else
        {
            int ved=0;
            for(it=cnt.begin();it!=cnt.end();it++)
            {
                if(*it>y)
                    break;
                v[++ved]=*it;
            }
            for(int j=1;j<=ved;j++)
                cnt.erase(v[j]);
        }
        cout << cnt.size() << endl;
    }
    return 0;
}
