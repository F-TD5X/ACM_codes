#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10000];
int t,n;
ll ans;
int tire[1000<<10];

ll check(ll n)
{
	queue<int> s;
	while(n)
	{
		s.push(n%2);
		n>>=1;
	}
	int t=0,k=0;
	ll ret=0;
	while(!s.empty())
	{
		k=s.front();
		s.pop();
		if(k==0)
			ret+=1<<t;
		t++;
	}
	return ret;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("J.in","r",stdin);
    //freopen("J.out","w",stdout);
#endif
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		int m;
		int pos;
		sort(arr,arr+n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i==j)
					continue;
				ll m=arr[i]+arr[j];
				ll t=check(m);
				int pos = lower_bound(arr,arr+n,t)-arr;
				if(pos ==  i || pos == j || arr[pos]!=t)
					pos--;
				cout << i << " " << j << " " << m << " " << t << " " << arr[pos] << " " << (m ^ arr[pos]) << endl;
				if(pos!= i && pos!=j)
					ans=max(ans,m^arr[pos]);
				if(i!= n-1 && j!=n-1)
					ans=max(ans,m^arr[n-1]);
			}
		cout <<ans <<endl;
	}
}
