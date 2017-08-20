#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include<queue>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
struct Node
{
    int x,y,step;
    Node(int x=0,int y=0,int step=0):x(x),y(y),step(step){}
}ans;
queue<Node>q;
int n,m;
char ma[555][555];
int vi[555][555];
int dis_x[4]={1,0,-1,0},dis_y[4]={0,1,0,-1};

Node bfs()
{
    Node now;
    int xx,yy;
    while(!q.empty())
    {
        now = q.front();
        if(now.x == n-1 && now.y == m-1)
            return now;
        q.pop();
        if(vi[now.x][now.y])
            continue;
        vi[now.x][now.y]=1;
        for(int i=0;i<4;i++)
        {
            xx = now.x + (ma[now.x][now.y]-'0')*dis_x[i];
            yy = now.y + (ma[now.x][now.y]-'0')*dis_y[i];
            if(0<=xx && xx <n && 0<=yy && yy<m)
            {
                q.push(Node(xx,yy,now.step+1));
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
    while(cin >> n>> m)
    {
        while(!q.empty())
            q.pop();
        ans = Node(0,0,0);
        memset(ma,0,sizeof(ma));
        memset(vi,0,sizeof(vi));
        for(int i =0;i<n;i++)
            scanf("%s",ma[i]);
        q.push(Node(0,0,0));
        ans = bfs();
        if(ans.x == n-1 && ans.y == m-1)
            cout <<ans.step<<endl;
        else
            cout << "IMPOSSIBLE"<<endl;
    }
    return 0;
}
