/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
const int maxn=1111;
struct Node{
	ll x,m;
	bool operator<(const Node &t)const{
		if(x==t.x)
			return m<t.m;
		return x<t.x;
	}
};
int x[maxn],m[maxn];
priority_queue<Node> q1,q2;
ll ans=0;

ll solve(priority_queue<Node> & q){
	ll ret=0;
	while(!q.empty()){
		Node cur=q.top();
		q.pop();
		ll t=(cur.m+k-1)/k;
		ll d=0;
		if(cur.m %k!=0)
			d=k-cur.m%k;
		ret+=t*cur.x*2;
		while(d){
			if(q.size()==0)
				break;
			Node cur=q.top();
			q.pop();
			int de=min(d,cur.m);
			cur.m-=de;
			d-=de;
			if(cur.m!=0)
				q.push({cur});
		}
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("J.2.in","r",stdin);
    //freopen("J.2.out","w",stdout);
#endif
	cin >> n >> k;
	for(int x,m,i=0;i<n;i++){
		cin >> x >> m;
		if(x > 0)
			q1.push({x,m});
		else 
			q2.push({-x,m});
		
	}
	ans+=solve(q1);
	ans+=solve(q2);
	cout <<ans << endl;
	return 0;
}
