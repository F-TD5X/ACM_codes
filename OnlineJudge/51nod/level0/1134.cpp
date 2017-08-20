/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5;
int loc[maxn];
int n;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1134.in","r",stdin);
    //freopen("1134.out","w",stdout);
#endif
	cin >>n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	loc[0]=a[0];
	int k=1;
	for(int pos,i=1;i<n;i++){
		if(a[i] > loc[k-1])
			loc[k++]=a[i];
		else{
			pos=lower_bound(loc,loc+k,a[i])-loc;
			loc[pos]=a[i];
		}
	}
	cout << k << endl;

	return 0;
}
