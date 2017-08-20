<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+100;
vector<int> mp[maxn];
int n;
bool vis[maxn];
int down[maxn];
int up[maxn],cost[maxn];
int ans=2e9;

void preDo(int st,int u)
{
	down[st]=-2e9;
	for(auto v:mp[st])
		if(u!=v){
			preDo(v,st);
			down[st]=max(down[st],max(down[v],cost[v]));
		}
}

void preSolve(int rt,int u)
{
	int b1=-2e9,s1=0,b2=-2e9,s2=0;
	for(auto v:mp[rt])
		if(v!=u)
			if(max(down[v],cost[v])>b1){
				b2=b1;
				s2=s1;
				b1=max(down[v],cost[v]);
				s1=v;
			}
		else if(max(down[v],cost[v])>b2){
				b2=max(down[v],cost[v]);
				s2=v;
		}
	for(auto v:mp[rt])
		if(v!=u){
			if(v==s1)
				up[v]=max(up[rt],max(cost[u],b2));
			else
				up[v]=max(up[rt],max(cost[u],b1));			
			preSolve(v,rt);
		}
}

void solve(int st,int u)
{
	int c=max(cost[st],cost[u]+1);	
	for(auto v:mp[st]){
		if(v!=u){
			c=max(c,max(cost[v]+1,down[v]+2));
			solve(v,st);
		}
	}
	c=max(c,up[st]+2);
	ans=min(ans,c);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> cost[i];
	}
	for(int u,v,i=0;i<n-1;i++){
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	cost[0]=up[1]=-2e9;
	preDo(1,0);
	preSolve(1,0);
	solve(1,0);
	cout << ans << endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+100;
vector<int> mp[maxn];
int n;
bool vis[maxn];
int down[maxn];
int up[maxn],cost[maxn];
int ans=2e9;

void preDo(int st,int u)
{
	down[st]=-2e9;
	for(auto v:mp[st])
		if(u!=v){
			preDo(v,st);
			down[st]=max(down[st],max(down[v],cost[v]));
		}
}

void preSolve(int rt,int u)
{
	int b1=-2e9,s1=0,b2=-2e9,s2=0;
	for(auto v:mp[rt])
		if(v!=u)
			if(max(down[v],cost[v])>b1){
				b2=b1;
				s2=s1;
				b1=max(down[v],cost[v]);
				s1=v;
			}
		else if(max(down[v],cost[v])>b2){
				b2=max(down[v],cost[v]);
				s2=v;
		}
	for(auto v:mp[rt])
		if(v!=u){
			if(v==s1)
				up[v]=max(up[rt],max(cost[u],b2));
			else
				up[v]=max(up[rt],max(cost[u],b1));			
			preSolve(v,rt);
		}
}

void solve(int st,int u)
{
	int c=max(cost[st],cost[u]+1);	
	for(auto v:mp[st]){
		if(v!=u){
			c=max(c,max(cost[v]+1,down[v]+2));
			solve(v,st);
		}
	}
	c=max(c,up[st]+2);
	ans=min(ans,c);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> cost[i];
	}
	for(int u,v,i=0;i<n-1;i++){
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	cost[0]=up[1]=-2e9;
	preDo(1,0);
	preSolve(1,0);
	solve(1,0);
	cout << ans << endl;
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+100;
vector<int> mp[maxn];
int n;
bool vis[maxn];
int down[maxn];
int up[maxn],cost[maxn];
int ans=2e9;

void preDo(int st,int u)
{
	down[st]=-2e9;
	for(auto v:mp[st])
		if(u!=v){
			preDo(v,st);
			down[st]=max(down[st],max(down[v],cost[v]));
		}
}

void preSolve(int rt,int u)
{
	int b1=-2e9,s1=0,b2=-2e9,s2=0;
	for(auto v:mp[rt])
		if(v!=u)
			if(max(down[v],cost[v])>b1){
				b2=b1;
				s2=s1;
				b1=max(down[v],cost[v]);
				s1=v;
			}
		else if(max(down[v],cost[v])>b2){
				b2=max(down[v],cost[v]);
				s2=v;
		}
	for(auto v:mp[rt])
		if(v!=u){
			if(v==s1)
				up[v]=max(up[rt],max(cost[u],b2));
			else
				up[v]=max(up[rt],max(cost[u],b1));			
			preSolve(v,rt);
		}
}

void solve(int st,int u)
{
	int c=max(cost[st],cost[u]+1);	
	for(auto v:mp[st]){
		if(v!=u){
			c=max(c,max(cost[v]+1,down[v]+2));
			solve(v,st);
		}
	}
	c=max(c,up[st]+2);
	ans=min(ans,c);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> cost[i];
	}
	for(int u,v,i=0;i<n-1;i++){
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	cost[0]=up[1]=-2e9;
	preDo(1,0);
	preSolve(1,0);
	solve(1,0);
	cout << ans << endl;
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
