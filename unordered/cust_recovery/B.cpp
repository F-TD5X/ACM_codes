/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20;
int n,m;
ll w1[maxn],w2[maxn];
ll stat=1;
set<ll> ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> w1[i];
	for(int j=0;j<m;j++){
		cin >> w2[j];
		stat*=3;
	}
	sort(w2,w2+m);
	for(int i=0;i<stat;i++){
		ll l=0,r=0;
		int t=i;
		for(int i=0;i<m;i++){
			int f=t%3;
			t/=3;
			if(f==0)
				l+=w2[i];
			else if(f==1)
				r+=w2[i];
		}
		if(l!=r)
			continue;
		for(int j=0;j<n;j++)
			ans.insert(w1[j]+l+r);
	}
	for(auto x:ans)
		cout <<x <<endl;
	return 0;
}
