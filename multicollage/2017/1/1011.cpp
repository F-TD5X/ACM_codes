/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
	int kase=1;
	while(cin >> n >> k){
		printf("Case #%d: ",kase++);
		if(n>=k)
			cout << k<<endl;
		else{
			k-=n;
			int tn=n-1;
			if((k/tn)%2)
				if(k%tn==0)
					cout << n-1 << endl;
				else
					cout << k%tn<<endl;
			else{
				if(k%tn==0)
					cout << n << endl;
				else
					cout << k%tn << endl;
			}
		}
	}
	return 0;
}
