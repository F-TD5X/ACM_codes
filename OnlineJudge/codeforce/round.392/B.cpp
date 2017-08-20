#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[1000];
string s;
char st[4];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> s;
	for(int k=0,c=0,i=0;i<s.size();i++,k%=4)
	{
		if(s[i]!='!' && st[k]==0)
		{
			st[k]=s[i];
			c++;
		}
		k++;
		if(c==4)
			break;
	}
	//cout << st<<endl;
	for(int k=0,i=0;i<s.size();i++,k%=4)
	{
		if(s[i]=='!')
			ans[st[k]]++;
		k++;
	}
	cout << ans['R']<<" " << ans['B']<<" " << ans['Y']<<" " << ans['G']<<endl;
	return 0;
}
