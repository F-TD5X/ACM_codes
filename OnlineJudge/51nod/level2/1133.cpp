/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	int l,r;
	bool operator<(const Node &t)const{
		if(r ==t.r)
			return r-l < t.r-t.l;
		return r<t.r;
	}
}a[11111];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1133.in","r",stdin);
    //freopen("1133.out","w",stdout);
#endif
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i].l >> a[i].r;
	}
	sort(a,a+n);
	int ans=0;
	for(int r=-0x3f3f3f3f,i=0;i<n;i++){
		if(r<=a[i].l){
			ans++;
			r=a[i].r;
		}
	}
	cout <<ans << endl;
	return 0;
}
