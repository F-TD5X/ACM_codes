/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
#endif
	cin >> T;
	while(T--){
		cin >> n;
		int ans=0;
		for(int i=1;i<sqrt(n-1);i++)
			if((n-1)%i==0)
				ans+=2;
		if(sqrt(n-1)-int(sqrt(n-1))<1e-6)
			ans+=1;
		cout << ans << endl;
	}
	return 0;
}
