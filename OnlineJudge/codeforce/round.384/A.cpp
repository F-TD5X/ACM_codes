#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
string s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n>>a>>b;
	cin >> s;
	a--;b--;
	int ans=0;
	if(s[a]==s[b])
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[a])
		{
			ans=1;
			break;
		}
	}
	if(ans)
	{
		cout <<ans<<endl;
		return 0;
	}
	else
	{
		cout << fabs(a-b)<<endl;
		return 0;
	}
	return 0;
}
