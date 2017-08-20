#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<ctime>
#define MAXN 100001
using namespace std;
typedef long long ll;
ll n,m,T;
ll x,y,cost;
ll f[MAXN],sum[MAXN];
double dp[MAXN];

struct Edge{
    ll y,x,cost;
    Edge(){}
    Edge(ll x,ll y, ll cost):x(x),y(y),cost(cost){}
};
struct Node{
    ll v,len;
    Node(){}
    Node(ll x,ll y):v(x),len(y){}
};
vector<Edge> edge;
vector<Node> vet[MAXN];



bool cmp(const Edge &a,const Edge &b){return a.cost < b.cost;}

ll fi(ll x){
    if(f[x] == x) return x;
    else return f[x] = fi(f[x]);
}

long long Kruskal(){
    ll s1,s2;
    long long ans = 0;
    for(ll i =1;i<=n;i++)
        f[i]=i;
    for(int i =0;i<edge.size();i++)
    {
        s1=fi(edge[i].x);
        s2=fi(edge[i].y);
        if(s1 != s2)
        {
            f[s1]=s2;
            vet[edge[i].x].push_back(Node(edge[i].y,edge[i].cost));
            vet[edge[i].y].push_back(Node(edge[i].x,edge[i].cost));
            ans+=edge[i].cost;
        }
    }
    return ans;
}

void dfs(ll r,ll fa){
   sum[r] = 1;
   for(ll i = 0;i < (int)vet[r].size();i++)
    {
      ll son = vet[r][i].v;
      ll len = vet[r][i].len;
      if(son == fa)continue;
      dfs(son,r);
      sum[r] += sum[son];
      dp[r] += dp[son] + ((double)sum[son] * (n - sum[son])) * len;
   }
}
int main()
{
    //freopen("1001.in","r",stdin);
    //freopen("1001","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        for(ll i =1;i<=n;i++)
            vet[i].clear();
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        edge.clear();
        scanf("%d%d",&n,&m);
        for(ll i =0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&cost);
            edge.push_back(Edge(x,y,cost));
        }
        sort(edge.begin(),edge.end(),cmp);
        long long ans = Kruskal();
        long long s = n*(n-1)/2;
        dfs(1,0);
        printf("%I64d %.2f\n",ans,dp[1] / (double)s);
       // cout << clock()<<endl;
    }
}
