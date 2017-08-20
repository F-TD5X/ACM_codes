#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	string s;
	int n,a,b,k;
	cin >> n >> a>>b>>k;
	cin >> s;
	vector<int> ans;
	int i=0,j=0;
	for(int i=0,c=1;i<n;i++,c++)
	{
		if(s[i]=='1')
			c=0;
		else
		{
			if(c==b)
				ans.push_back(i+1),c=0;
		}
	}
	cout << ans.size()-a+1<<endl;
	for(int k=0;k<ans.size()-a+1;k++)
		cout << ans[k]<<" ";
	cout << endl;
	return 0;
}
