#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n[10]={6,2,5,5,4,5,6,3,7,6};

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
	int t,n,n1,n2,n3,n4;
	cin >> t;
	while(t--)
	{
		n1=n2=n3=n4=0;
		cin >> n;
		n1=n/2;
		if(n%2)
		{
			n1--;
			n2=7;
		}
		if(n==4)
			cout << 11 <<" " << 4<<endl;
		else if(n<=3)
			puts("I am so stupid");
		else if(n1>=3 && !n2)
		{
			for(int i=0;i<n1;i++)
				cout << 1;
			cout <<" ";
			if(n2)
				cout << 7;
			cout <<"77";
			for(int i=0;i<n1-3;i++)
				cout << 1;
			cout << endl;
		}
		else if(n2)
		{
			cout<<7;
			for(int i=0;i<n1;i++)
				cout <<1;
			cout << " " ;
			cout << 1;
			cout << 7;
			for(int i=0;i<n1-1;i++)
				cout << 1;
			cout <<endl;
		}
	}
	return 0;
}
