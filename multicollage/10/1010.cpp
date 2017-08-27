/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
const int maxn=1e5+10;
ll ans;
const int INF=0x3f3f3f3f;

struct P{
	int l,r;
	P(int l=0,int r=0):l(l),r(r){}
	bool operator<(const P&t) const{
		return r<t.r;
	}
}v[maxn];

set<P> s;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1010.in","r",stdin);
    //freopen("1010.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&v[i].l,&v[i].r);
		}
		set<P>::iterator it;
		for(int i=0;i<n;i++){
			it=s.lower_bound(P(0,v[i].l));
			if(it==s.begin()){
				s.insert(v[i]);
			}
			else{
				--it;
				P tmp((*it).l,v[i].e);
				s.erase(it);
				s.insert(tmp);
			}
		}
		ll ans=0;
		for(auto t:s){
			//cout << t.l <<" " << t.r << endl;
			ans+=t.r-t.l;
		}
		printf("%d %lld\n",s.size(),ans);
	}
	return 0;
}
