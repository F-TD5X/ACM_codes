<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> desk;
int n;
int x;
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	set<int>::iterator it;
	n*=2;
	while(n--)
	{
		cin >> x;
		if((it=desk.find(x))!=desk.end())
		{
			desk.erase(it);
		}
		else
		{
			desk.insert(x);
			ans=max(ans,(int)desk.size());
		}
	}
	cout << ans<<endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> desk;
int n;
int x;
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	set<int>::iterator it;
	n*=2;
	while(n--)
	{
		cin >> x;
		if((it=desk.find(x))!=desk.end())
		{
			desk.erase(it);
		}
		else
		{
			desk.insert(x);
			ans=max(ans,(int)desk.size());
		}
	}
	cout << ans<<endl;
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
