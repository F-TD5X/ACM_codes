//骑士的移动
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int mv[8][2]={1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
int mp[9][9];
int aim_x,aim_y,c2,c4;
char c1,c3;
struct Node
{
    int x,y,step;
    Node(int x,int y,int step=0):x(x),y(y),step(step){}
};

int bfs(int b_x,int b_y)
{
    queue<Node>q;
    q.push(Node(b_x,b_y,0));
    while(!q.empty())
    {
        Node now=q.front();
        q.pop();
        if(now.x==aim_x && now.y==aim_y)
        {
            cout << "To get from "<<c1<<c2 <<" to " <<c3<<c4 << " takes " <<now.step <<" knight moves."<<endl;
            return 0;
        }
        for(int i=0;i<8;i++)
        {
            int xx=now.x+mv[i][0],yy=now.y+mv[i][1];
            if(xx >0 && yy>0 && xx<9 && yy<9)
            {
                q.push(Node(xx,yy,now.step+1));
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("UVa439.in","r",stdin);
    //freopen("UVa439.out","w",stdout);
#endif
    while(cin>>c1>>c2>>c3>>c4)
    {
        aim_x=c3-'a'+1;
        aim_y=c4;
        bfs(c1-'a'+1,c2);
    }
    return 0;
}
