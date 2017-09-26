/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int gcd;
int lcm;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m)){
		n--,m--;
		if(n==m)
			cout << 1+n << endl;
		else{
			if(n>m)
				swap(n,m);
			if(m%n==0){
				cout << 1+m<<endl;
			}else{
				int t=n-m%n;
				cout << (n-1)/t+n/t+m/t+(m-1)/t<<endl;
			}
		}
	}
	return 0;
}
