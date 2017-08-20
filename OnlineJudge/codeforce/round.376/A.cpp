#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[100];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	for(int i='a';i<='z';i++)
		arr[i]=i-'a';
	string s;
	int now = arr['a'];
	int ans;
	while(cin >>s)
	{
		ans=0;
		now=arr['a'];
		for(auto c:s)
		{
			ans+=min(abs(arr[c]-now),abs(26-abs(arr[c]-now)));
			now=arr[c];
		}
		cout << ans<<endl;
	}
	return 0;
}
