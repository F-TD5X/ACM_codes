#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	int t;
	int n;
	cin >>t;
	while(t--)
	{
		cin >> n;
		if(n%4==1 || n%4==0)
			cout <<"yes"<<endl;
		else
			cout <<"no"<<endl;
	}
	return 0;
}
