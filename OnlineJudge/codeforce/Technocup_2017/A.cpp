#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
bool flag;
vector<int> que;
stack<int>ans;
void solve()
{
	double n=b;
	while(n)
	{
		if((int)n%10 == 1)
		{
			n-=1;
			n/=10;
			ans.push(n);
		}
		else
		{
			n/=2;
			ans.push(n);
		}
		if(n==a)
		{
			flag=1;
			break;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >>a >> b;
	solve();
	if(flag)
	{
		cout <<"YES"<<endl;
		cout <<ans.size()+1<<endl;
		while(!ans.empty())
		{
			cout << ans.top() <<" ";
			ans.pop();
		}
		cout << b<<endl;
	}
	else
		cout <<"NO"<<endl;
	return 0;
}
