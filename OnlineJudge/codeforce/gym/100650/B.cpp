#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	string s;
	int num;
}fa[1111];
int n,d,vi[1111];
map<string,int> mp;
int all=1;
string s1,s2;
vector<int> ma[1111];

bool cmp(Node a,Node b)
{
	if(a.num==b.num)
		return a.s<b.s;
	return a.num>b.num;
}

int get(string s)
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
	for(auto a:ma[x])
		ans+=dfs(a,d-1);
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)	
	{
		printf("Tree %d:\n",cas);
		scanf("%d%d",&n,&d);
		mp.clear();
		all=1;
		memset(vi,0,sizeof(vi));
		for(int i=0;i<1111;i++)
			ma[i].clear();
		for(int i=0,m;i<n;i++)
		{
			cin >>s1>>m;
			while(m--)
			{
				cin>>s2;
				ma[get(s1)].push_back(get(s2));
			}
		}
		for(int i=1;i<all;i++)
			fa[i].num=dfs(i,d);
		sort(fa+1,fa+all,cmp);
		int INF=0x3f3f3f;
		for(int i=1;i<=min(3,all-1);i++)
		{
			if(fa[i].num==0)
				break;
			vi[i]=1;
			INF=fa[i].num;
			cout << fa[i].s <<" " << fa[i].num<<endl;
		}
		for(int i=1;i<all;i++)
		{
			if(vi[i]==1)
				continue;
			if(fa[i].num<INF)
				break;
			if(fa[i].num==INF)
				cout <<fa[i].s <<" "<<fa[i].num<<endl;
		}
		cout << endl;
	}	
	return 0;
}
