/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int t;
int ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
	while(cin >> n){
		ans=0;
		while(n--){
			cin >> t;
			if(t<=35)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
