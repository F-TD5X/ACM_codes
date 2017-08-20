/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int  l,r;

ll solve(int n,int l,int r){
    ll ret = 0;
    for(int i = l,j = i;i <= r;i = j+1){
        j = n/(n/i);
		j = min(j,r);
        ret += 1LL*(j-i+1)*(n/i);
    }
	return ret;
}
ll query(int n,int k){
    ll ans = 0,x = k,y = 1;
    while(x <= n){
        ans += solve(n,x,min(x+y-1,1LL*n));
        x *= 10;y *= 10;
    }
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("loj_6083.in","r",stdin);
    //freopen("loj_6083.out","w",stdout);
#endif
	cin >> l >> r;
	for(int i=1;i<=9;i++){
		cout << query(r,i) - query(l-1,i) << endl;
	}
	return 0;
}
