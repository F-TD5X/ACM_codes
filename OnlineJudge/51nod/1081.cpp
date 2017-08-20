#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+100;
ll pre[maxn],a[maxn];
int n,q;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1081.in","r",stdin);
    //freopen("1081.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		pre[i]=pre[i-1]+a[i];
	}
	cin >>q;
	for(int b,l,i=1;i<=q;i++)
	{
		cin >>b >> l;
		cout << pre[b+l-1]-pre[b-1]<<endl;
	}
	return 0;
}
