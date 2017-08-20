#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int n;
	string s;
	cin >> n >> s;
	int a=0,d=0;
	for(auto p:s)
	{
		if(p=='A')
			a++;
		else
			d++;
	}
	if(a>d)
		puts("Anton");
	else if(a==d)
		puts("Friendship");
	else
		puts("Danik");
	return 0;
}
