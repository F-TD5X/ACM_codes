#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e8;
int n;
int arr[maxn];
int *pos;
int m;
int a2[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	cin >> m;
	for(int t=0,i=0;i<m;i++){
		cin >> t;
		pos= upper_bound(arr,arr+n,t);
		if( *pos >= t)
			cout << *pos << endl;
		else
			cout <<"Dr. Samer cannot take any offer :(." << endl;
	}
	return 0;
}
