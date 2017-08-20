#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
int arr[maxn];
int ans=0;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
			cout <<"NO"<<endl;
			return 0;
		}
		else if(arr[i]%2==1)
		{
			if(i==n-1)
			{
				cout <<"NO"<<endl;
				return 0;
			}
			arr[i+1]--;
		}
	}
	cout <<"YES"<<endl;
	return 0;
}
