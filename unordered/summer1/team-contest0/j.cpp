#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include<set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
struct p123
{
    int ma[1111][1111];
}g[10];
int h,w,b;
set<int>s;

int disx[8]={1,1,0,-1,-1,-1,0,1};
int disy[8]={0,1,1,1,0,-1,-1,-1};
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("j.in","r",stdin);
    //freopen("j.out","w",stdout);
#endif
    while(cin >> w >> h >> b)
    {
        ans =0;
        s.clear();
        memset(g,0,sizeof(g));
        for(int i=0;i<11*h;i++)
        {
            if(i>=h)
            {
                for(int j=0;j<11*w;j++)
                {
                    g[0].ma[i][j]=g[0].ma[i%h][j%w];
                }
            }
            else
                for(int j=0;j<w;j++)
                {
                    cin >> g[0].ma[i][j];
                    g[0].ma[i][j];
                }
        }
        for(int k=1;k<=b;k++)
        {
            for(int i=0;i<11*h;i++)
            {
                for(int j=0;j<11*w;j++)
                {
                    g[k].ma[i][j]+=g[k-1].ma[i][j];
                    for(int d=0;d<8;d++)
                    {
                        g[k].ma[i][j]+= g[k-1].ma[i+disx[d]][j+disy[d]];
                    }
                }
            }
        } 
        for(int i=5*h;i<6*h;i++)
        {
            for(int j = 5*w ;j<=6*w;j++)
            {
               s.insert(g[b].ma[i][j]);
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}
