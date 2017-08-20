#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void pll(bool a,int n)
{
	if(a)
	{
		cout <<"#";
		n--;
		while(n--)
			cout <<".";
		cout <<endl;
	}
	else
	{
		n--;
		while(n--)
			cout <<".";
		cout <<"#"<<endl;
	}
}

void pl(int n)
{
	while(n--)
		cout <<"#";
	cout <<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("12.in","r",stdin);
    //freopen("12.out","w",stdout);
#endif
	int n,m;
	while(cin >> n >> m)
		for(int i=0;i<n;i++)
			if(i%2==0)
				pl(m);
			else
				if(i/2%2)
					pll(1,m);	
				else
					pll(0,m);
	return 0;
}
