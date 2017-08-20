#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=2e5+100;
int a[maxn];
set<int> s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
#endif
	cin >> n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!s.count(a[i]-1)){
			ans++;
			s.insert(a[i]);
		}
		else
			s.insert(a[i]);
	}
	cout << ans << endl;

	return 0;
}
