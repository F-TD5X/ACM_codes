#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000000],ans[1000000];
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >>n;
	cin >> s;
	int mid=n>>1;
	int l,r;
	int i;
	if(n&1)
	{
		l=mid-1;
		r=mid+1;
		ans[mid]=s[0];
		i=1;
	}
	else
	{
		l=mid-1;
		r=mid;
		i=0;
	}
	for(;i<n;i+=2)
	{
		ans[l--]=s[i];
		ans[r++]=s[i+1];
	}
	cout << ans <<endl;
	return 0;
}
