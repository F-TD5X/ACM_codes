#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[40],t[40];
int ans[40];

void make(int b)
{
	for(int i=0;i<b-i;i++)
		swap(a[i],a[b-i]);
	cout << n-b <<" " ;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa120.in","r",stdin);
    //freopen("UVa120.out","w",stdout);
#endif
	string s;
	while(getline(cin,s))
	{
		cout <<s<<endl;
		stringstream ss(s);
		n=0;
		while(ss>>a[n])
			n++;
		sort(t,t+n);
		for(int i=n-1;i>0;i--)
		{
			int pos=max_element(a,a+i+1)-a;
			if(pos==i)
				continue;
			if(pos>0)
				make(pos);
			make(i);
		}
		cout << 0 <<endl;
	}
	return 0;
}
