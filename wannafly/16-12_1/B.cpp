#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6+5;
int a[maxn][27],f[maxn],cnt;
string s[maxn];

inline void insert(string str)
{
	int len=str.length(),now=0;
	for(int i=len-1;i>=0;--i){
		if(!a[now][str[i]-'a'])
			a[now][str[i]-'a']=++cnt;
		now = a[now][str[i]-'a'];
		++f[now];
	}
}

inline int calc(string str)
{
	int len=str.length(),now=0,ret=0;
	for(int i=len-1;i>=0;--i){
		for(int j=str[i]-'a'+1;j<26;++j)
			ret+=f[a[now][j]];
		now=a[now][str[i]-'a'];
	}
	for(int i=0;i<26;++i)
		ret+=f[a[now][i]];
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,nid;
	ll ans;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			cin >> s[i];
		sort(s,s+n);
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		ans=0,cnt=0;
		for(int i=0;i<n;i++){
			insert(s[i]);
			ans+=calc(s[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
