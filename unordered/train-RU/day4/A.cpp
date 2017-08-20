#include<bits/stdc++.h>
using namespace std;
char ma[1111][1111];
int vi[1111][1111];
int ans,ans2;
int n,t;

int dfs(int x,int y)
{
    //cout << x<< " "<< y << " " <<ma[x][y] <<endl;
    if(x == n && y == n)
    {
        ans ++ ;
        return 0;
    }
    if(ma[x][y] == '#' || x > n || y > n||vi[x][y])
    {
        return 0;
    }
    else
    {
        vi[x][y] =1;
        dfs(x+1,y);
        dfs(x,y+1);
        vi[x][y]=0;
    }
}
int dfs2(int x,int y)
{
    if(x == n && y == n)
    {
        ans2 ++ ;
        return 0;
    }
    if(ma[x][y] == '#' || x > n || y > n|| x < 1 || y < 1||vi[x][y])
    {
        return 0;
    }
    else
    {
        vi[x][y] =1;
        dfs2(x+1,y);
        dfs2(x,y+1);
        dfs2(x-1,y);
        dfs2(x,y-1);
        vi[x][y]=0;
    }
}
int main()
{
    while(cin >> n)
    {
    ans = 0;
    ans2= 0;
    memset(ma,0,sizeof(ma));
    memset(vi,0,sizeof(vi));
    int ox,y;
    for(int i =1;i<=n;i++)
      scanf("%s",ma[i]+1);
      dfs(1,1);
      //cout << ans <<endl;
      if(ans)
      {
          cout << ans <<endl;
      }
      else
      {
          memset(vi,0,sizeof(vi));
          dfs2(1,1);
          //cout << ans2 <<endl;
          if(ans2)
             cout << "THE GAME IS A LIE"<<endl;
          else 
            cout << "INCONCEIVABLE"<<endl;
      }
    }
    return 0;
}
