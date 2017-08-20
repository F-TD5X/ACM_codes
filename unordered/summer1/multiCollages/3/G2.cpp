#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
struct ENode
{
  int ad;
  int num;
};
vector<ENode> e[100010];
bool u[100010];
int sum=0;
int dfs(int rt)
{
  u[rt]=1;
  int s=0;
  for(int i=0;i<e[rt].size();i++)
  {
    if(u[e[rt][i].ad]==0)
    {
      e[rt][i].num=dfs(e[rt][i].ad);
      s+=e[rt][i].num;
    }
  }
  sum+=s;
  if(s==0) s=1;
  if(s&1) s=1;
  else s=2;
  return s;
}
int dfs2(int rt)
{
  int mm=0;
  for(int i=0;i<e[rt].size();i++)
  {
    if(e[rt][i].num==1)
    {
      int tmp=dfs2(e[rt][i].ad);
      if(tmp-1>mm) mm=tmp-1;
    }
    else if(e[rt][i].num==2)
    {
      int tmp=dfs2(e[rt][i].ad);
      if(tmp+1>mm) mm=tmp+1;
    }
  }
  return mm;
}
int du[100010];
int qiuCha(int n)
{
  int co=0;
  for(int i=1;i<=n;i++)
  {
    if(du[i]==1) co++;
  }
  if(co%2==0) return 0;
  return dfs2(1);
}
int main()
{
  int t,n,x,y;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) e[i].clear();
    memset(du,0,sizeof(du));
    for(int i=0;i<n-1;i++)
    {
      scanf("%d%d",&x,&y);
      du[x]++;//记录支路的数量
      du[y]++;
      ENode tmp;
      tmp.ad=y;
      tmp.num=0;
      e[x].push_back(tmp);
      tmp.ad=x;
      e[y].push_back(tmp);
    }
    memset(u,0,sizeof(u));
    sum=0;
    dfs(1);
    int cha=qiuCha(n);
    printf("%d\n",sum-cha);
  }
  return 0;
}
