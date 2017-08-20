#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
stack<int> s;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
	while(cin >> n)
	{
		while(n)
		{
			s.push(n%2);
			n/=2;
		}
		while(!s.empty())
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}

	return 0;
}
