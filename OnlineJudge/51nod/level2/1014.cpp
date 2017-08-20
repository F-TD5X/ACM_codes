/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,a;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1014.in","r",stdin);
    //freopen("1014.out","w",stdout);
#endif

	bool flag=0;
	cin >> p >> a;
	for(int i=1;i<=p;i++){
		if(i%p*i%p==a){
			cout <<i << " ";
			flag=1;
		}
	}
	if(!flag)
		cout << "No Solution"<<endl;
	return 0;
}
