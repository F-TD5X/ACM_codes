#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
struct Node
{
    string s;
    int num;
}fa[1111];

int n,d,vi[1111];
map<string,int> mp;
int all=1;
string str1,str2;
vector<int> edge[1111];

bool cmp(Node a,Node b)
{
    if(a.num==b.num)
        return a.s<b.s;
    return a.num>b.num;
}

int get_id(string s)
{
    if(mp[s]==0)
    {
        mp[s]=all;
        fa[all].s=s;
        fa[all].num=0;
        all++;
    }
    return mp[s];
}

int dfs(int x,int d)
{
    if(d==0)
        return 1;
    int ans=0;
    for(int i=0;i<edge[x].size();i++)
        ans+=dfs(edge[x][i],d-1);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
    //freopen("B-0.out","w",stdout);
#endif
    int T;
    cin >> T;
    for(int cas=1;cas<=T;cas++)
    {
        printf("Tree %d:\n",cas);
        cin >> n>>d;
        mp.clear();
        all=1;
        memset(vi,0,sizeof(vi));
        for(int i=0;i<1111;i++)
            edge[i].clear();
        for(int i=0;i<n;i++)
        {
            int m;
            cin >> str1>>m;
            for(int j=0;j<m;j++)
            {
                cin >>str2;
                edge[get_id(str1)].push_back(get_id(str2));
            }
        }
        for(int i=1;i<all;i++)
        {
            fa[i].num=dfs(i,d);
        }
        sort(fa+1,fa+all,cmp);
        int ccc=0x3f3f3f;
        for(int i=1;i<=min(3,all-1);i++)
        {
            if(fa[i].num==0)
                break;
            vi[i]=1;
            ccc=fa[i].num;
            cout << fa[i].s <<" "<<fa[i].num<<endl;
        }
        for(int i=1;i<all;i++)
        {
            if(vi[i]==1)
                continue;
            if(fa[i].num<ccc)
                break;
            if(fa[i].num==ccc)
            {
                cout <<fa[i].s<<" " << fa[i].num<<endl;
            }
        }
        cout << endl;
    }
    return 0;
}

