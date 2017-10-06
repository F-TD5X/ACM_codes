/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn  = 1e6+10;
ll a[maxn];
multiset<ll> s;

int main(){
#ifndef ONLINE_JUDGE
    //freopen("6220.in","r",stdin);
    //freopen("6220.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		s.insert(a[i]);	
		if(a[i] % n == 0){
			cout << i <<" " << a[i] << endl;
			break;
		}
	}
	return 0;
}
