#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[1000001];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("9.in","r",stdin);
    //freopen("9.out","w",stdout);
#endif
	int T;
	cin >>T;
	int n;
	while(T--)
	{
		ans[0]=1;
		cin >> n;
		for(int i=1;i<=n;i++)
			ans[i]=ans[i-1]+4*(i-1)+1;
		cout << ans[n] << endl;
	}
	return 0;
}
