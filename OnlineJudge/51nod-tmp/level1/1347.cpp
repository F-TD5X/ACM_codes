#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1347.in","r",stdin);
    //freopen("1347.out","w",stdout);
#endif
	cin >>s;
	if(s.size()%2==1)
		puts("NO");
	else
	{
		int k=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i] == s[(i+s.size()/2)%s.size()])
				k++;
			else
				k=0;
		}
		if(k>=s.size())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
