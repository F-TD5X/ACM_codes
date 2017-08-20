/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100100],pre[100100];
int n;
int T;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1062.in","r",stdin);
    //freopen("1062.out","w",stdout);
#endif
	a[0]=0;a[1]=1;
	for(int i=2;i<=1e5+10;i++){
		if(i%2)
			a[i]=a[i/2]+a[i/2+1];
		else
			a[i]=a[i/2];
	}
	for(int i=0;i<1e5+10;i++)
		pre[i]=max(pre[i-1],a[i]);
	cin >> T;
	while(T--){
		cin >> n;
		cout << pre[n] << endl;
	}

	return 0;
}
