#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string ss;
string str;
int cnt[100000];
int ami,ama;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >> str;
		cnt[str.size()]++;
	}
	cin >> ss;
	int c=0;
	for(int i=1;i<ss.size();i++)
		c+=cnt[i];
	for(int j=1;j<=c;j++)
	{
		ami++;
		if(j%k==0)
			ami+=5;
	}
	ami++;
	c+=cnt[ss.size()];
	for(int j=1;j<=c-1;j++)
	{
		ama++;
		if(j%k==0)
			ama+=5;
	}
	ama++;
	cout << ami <<" " << ama<<endl;
	return 0;
}
