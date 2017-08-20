#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1111;
char ma[maxn][maxn];
int n,m;
int k,x,y;
int ans;
int cas;
pair<int,int> move_k[8]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
pair<int,int> move_q[8]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
vector<pair<int,int> > Q;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
    cas=0;
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        cas++;
        ans  = 0;
        memset(ma,0,sizeof(ma));
        Q.clear();
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            ma[x][y]='Q';
            Q.push_back(make_pair(x,y));
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            ma[x][y]='K';
            for(int i=0;i<8;i++)
            {
                int xx = x+move_k[i].first,yy=y+move_k[i].second;
                if(xx >=1&&xx<=n&&yy>=1&&y<=m)
                {
                    if(ma[xx][yy]==0)
                        ma[xx][yy]='B';
                }
            }
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            ma[x][y]='P';
        }
        for(int i=0;i<Q.size();i++)
        {
            int xp=Q[i].first,yp=Q[i].second;
            for(int j=0;j<8;j++)
            {
                int xx=xp,yy=yp;
                while(xx >=1&&xx<=n&&yy>=1&&yy<=m)
                {
                    xx+=move_q[j].first;
                    yy+=move_q[j].second;
                    if(ma[xx][yy]=='P' || ma[xx][yy]=='K')
                        break;
                    if(ma[xx][yy] == 0)
                        ma[xx][yy]='B';
                }
            } 
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                /*
                if(ma[i][j] == 0)
                    cout << 0 <<" ";
                else
                    cout << ma[i][j] <<" ";
                */
                ans += ma[i][j]==0?1:0;
            }
            //cout << endl;
        }
        printf("Board %d has %d safe squares.\n",cas,ans);
    }

    return 0;
}
