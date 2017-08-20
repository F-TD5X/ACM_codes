#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int n,k;
	cin >> n >> k;
	int time=4*60-k;
	int i=0,sum=0;
	for(;sum<=time;i++)
	{
		sum+=i*5;
	}
	cout << (i-2<=n?i-2:n) <<endl;
	return 0;
}
