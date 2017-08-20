#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>q[200000];
int color[200000];
int flag[200000];
int n,m;
int v[200000],d[200000],c[200000];
void dfs(int x,int cnt,int c)
{
   if(!color[x])
       color[x]=c;
   if(flag[x]>=cnt)
       return;
   if(cnt==0)
       return;
   flag[x]=cnt;
   for(int i=0;i<q[x].size();i++)
       dfs(q[x][i],cnt-1,c);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
       cin>>v[i]>>d[i]>>c[i];
    for(int i=q;i>=1;i--)
        dfs(v[i],d[i],c[i]);
    for(int i=1;i<=n;i++)
        cout<<color[i]<<endl;
    return 0;
}
