#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn = 1e6+10;
int T,x,y,n;
struct Node
{
    int x,num;
    Node(){}
    Node(int x,int y):x(x),num(y){}
};

vector<Node> G[maxn];
int childTree[maxn];
int u[maxn],sum;

int dfs(int x)
{
    u[x]=1;
    int s=0;
    for(int i=0;i<G[x].size();i++)
    {
        if(u[G[x][i].x] == 0)
        {
            cout << x << " " << i << " " << u[G[x][i].x] << endl;
            G[x][i].num = dfs(G[x][i].x);
            s+=G[x][i].num;
        }
    }
    sum+=s;
    if(s==0) s=1;
    if(s&1) s=1;
    else s=2;
    return s;
}

int dfs2(int x)
{
    int m=0;
    int tmp;
    for(int i=0;i<G[x].size();i++)
    {
        if(G[x][i].num = 1)
        {
            tmp = dfs2(G[x][i].x);
            m = max(tmp-1,m);
        }
        else if(G[x][i].num == 2)
        {
            tmp =dfs2(G[x][i].x);
            m = max(m,tmp+1);
        }
    }
    return m;
}

int getNodeNum(int x)
{
    int ret =0;
    for(int i =1;i<n;i++)
        if(childTree[i]==1) ret++;
    if(ret%2==0) return 0;
    else return dfs2(1);
}


int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        sum = 0;
        memset(childTree,0,sizeof(childTree));
        for(int i =0;i<n;i++)
            G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            cin >> x >> y;
            //记录支路数量
            childTree[x]++;
            childTree[y]++;
            //建树
            G[x].push_back(Node(y,0));
            G[y].push_back(Node(x,0));
        }
        memset(u,0,sizeof(u));
        dfs(1);
        int node = getNodeNum(n);
        cout << sum-node <<endl;
    }
}

