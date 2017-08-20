/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int pos[maxn];
set<int> vis;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	int n;
	cin >> n;
	int sum=0;
	for(int t,i=1;i<=n;i++){
		cin >> t;
		sum+=t;
		pos[i]=pos[i-1]+t;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int p1=(pos[i]+sum/3)%sum,p2=(pos[i]+2*sum/3)%sum;
		if(vis.count(pos[i]) || vis.count(p1) || vis.count(p2))
			continue;
		if(*lower_bound(pos,pos+n-1,p1)==p1 && *lower_bound(pos,pos+n-1,p2)==p2)
		{
			ans++;
			vis.insert(pos[i]);
			vis.insert(p1);
			vis.insert(p2);
		}
	}
	cout <<ans << endl;
	return 0;
}
