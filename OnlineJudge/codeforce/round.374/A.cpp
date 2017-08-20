#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char c;
vector<int> ans;
int cnt;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> c;
		if(c == 'B')
			cnt++;
		else
		{
			if(cnt!=0)
			ans.push_back(cnt);
			cnt=0;
		}
	}
	if (cnt >0)
		ans.push_back(cnt);
	cout << ans.size()<<endl;
	for(auto a:ans)
		cout << a <<" ";
	return 0;
}
