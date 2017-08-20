/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
const int mod=1e9+7;
int n;
char s[maxn];
struct Node{
	int v[maxn];
	char c;
	bool ok;
	int now;
	bool operator<(const Node &t) const{
		if(now!=t.now)
			return now<t.now;
		for(int i=now-1;i>=0;i--)
			if(v[i]!=t.v[i])
				return v[i]<t.v[i];
		return ok<t.ok;
	}
}c[26];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1002.in","r",stdin);
    //freopen("1002.out","w",stdout);
#endif
	int kase=1;
	while(~scanf("%d",&n)){
		for(int i=0;i<26;i++){
			c[i].now=0;c[i].ok=1;
		}
		for(int len,i=0;i<n;i++){
			scanf("%s",&s);
			len=strlen(s);
			c[s[0]-'a'].ok=0;
			for(int ch,j=0;j<len;j++){
				ch=s[len-j-1]-'a';
				while(c[ch].now <= j)
					c[ch].v[c[ch].now++]=0;
				c[ch].v[j]++;
			}
		}
		for(int i=0;i<26;i++){
			for(int j=0;j<c[i].now;j++){
				if(c[i].v[j]>=26){
					if(j==c[i].now-1)
						c[i].v[c[i].now++]=0;
					c[i].v[j+1]+=c[i].v[j]/26;
					c[i].v[j]%=26;
				}
			}
		}
		sort(c,c+26);
		for(int i=0;;i++){
			if(i==26)
				return 1;
			if(c[i].ok){
				for(int j=i-1;j>=0;j--)
					swap(c[j],c[j+1]);
				break;
			}
		}
		int ans=0;
		for(int i=0;i<26;i++){
			int t=i;
			for(int j=0;j<c[i].now;j++){
				ans=(ans+1ll*t*c[i].v[j])%mod;
				t=26ll*t%mod;
			}
		}
		printf("Case #%d: %d\n",kase++,ans);
	}

	return 0;
}
