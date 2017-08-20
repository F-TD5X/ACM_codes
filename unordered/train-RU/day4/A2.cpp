#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
    node(int x,int y):x(x),y(y){}
    node(){}
};
char ma[1111][1111];
int vi[1111][1111];
int n;
long long ans;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int dfs(int x,int y)
{
    if(x == n && y == n)
    {
        ans++;
        return 0;
    }
    if(ma[x][y] == '#' || x > n || y > n || vi[x][y])
      return 0;
    else
    {
        vi[x][y] = 1;
        dfs(x+1,y);
        dfs(x,y+1);
        vi[x][y]=0;
    }
}


int bfs(int x,int y)
{
    queue<node>q;
    q.push(node(x,y));
    vi[0][0]=1;
    while(!q.empty())
    {
        node t = q.front();
        q.pop();
        if(t.x ==n&&t.y == n) return 1;
        for(int i=0;i<4;i++)
        {
            node u(t.x+dx[i],t.y+dy[i]);
            if(u.x>=1&&u.y>=1&&u.x<=n&&u.y<=n&&!vi[u.x][u.y]&&ma[u.x][u.y]=='.')
            {
                vi[u.x][u.y]=1;
                q.push(u);
            }
        }
    }
    return 0;
}
int main()
{
    while(cin >> n)
    {
        memset(vi,0,sizeof(vi));
        memset(ma,0,sizeof(ma));
        ans=0;
        for(int p = 1;p <=n;p++)
            scanf("%s",&ma[p][1]);
        dfs(1,1);
        memset(vi,0,sizeof(vi));
        if(ans)
        {
            cout<<ans%(1<<31-1)<<endl;
        }
        else
        {
            int a=bfs(1,1);
            if(a)
              cout<<"THE GAME IS A LIE"<<endl;
            else
              cout<<"INCONCEIVABLE"<<endl;
        }
    }
}
