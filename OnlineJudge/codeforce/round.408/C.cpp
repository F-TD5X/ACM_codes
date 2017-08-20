<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=3e5+100;
vector<int> mp[maxn];
int a[maxn];
multiset<int,greater<int>> s;

inline void op(int x)
{
	auto it=s.find(x);
	s.erase(it);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int u,v,i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	int ans=2e9;
	int mx=-2e9;
	for(int i=1;i<=n;i++)
		s.insert(a[i]);
	for(int i=1;i<=n;i++){
		op(a[i]);
		for(int u:mp[i])
			op(a[u]);
		int cur=-2e9;
		if(!s.empty())
			cur=max(cur,*s.begin()+2);
		cur=max(cur,a[i]);
		for(int u:mp[i]){
			cur=max(cur,a[u]+1);
		}
		ans=min(ans,cur);
		s.insert(a[i]);
		for(int u:mp[i]) s.insert(a[u]);

	}
	printf("%d\n",ans);
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=3e5+100;
vector<int> mp[maxn];
int a[maxn];
multiset<int,greater<int>> s;

inline void op(int x)
{
	auto it=s.find(x);
	s.erase(it);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int u,v,i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	int ans=2e9;
	int mx=-2e9;
	for(int i=1;i<=n;i++)
		s.insert(a[i]);
	for(int i=1;i<=n;i++){
		op(a[i]);
		for(int u:mp[i])
			op(a[u]);
		int cur=-2e9;
		if(!s.empty())
			cur=max(cur,*s.begin()+2);
		cur=max(cur,a[i]);
		for(int u:mp[i]){
			cur=max(cur,a[u]+1);
		}
		ans=min(ans,cur);
		s.insert(a[i]);
		for(int u:mp[i]) s.insert(a[u]);

	}
	printf("%d\n",ans);
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=3e5+100;
vector<int> mp[maxn];
int a[maxn];
multiset<int,greater<int>> s;

inline void op(int x)
{
	auto it=s.find(x);
	s.erase(it);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int u,v,i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	int ans=2e9;
	int mx=-2e9;
	for(int i=1;i<=n;i++)
		s.insert(a[i]);
	for(int i=1;i<=n;i++){
		op(a[i]);
		for(int u:mp[i])
			op(a[u]);
		int cur=-2e9;
		if(!s.empty())
			cur=max(cur,*s.begin()+2);
		cur=max(cur,a[i]);
		for(int u:mp[i]){
			cur=max(cur,a[u]+1);
		}
		ans=min(ans,cur);
		s.insert(a[i]);
		for(int u:mp[i]) s.insert(a[u]);

	}
	printf("%d\n",ans);
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
