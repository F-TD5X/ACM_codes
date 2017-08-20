#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[1111];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa514.in","r",stdin);
    //freopen("UVa514.out","w",stdout);
#endif
	while(cin >> n && n)
	{
		while(cin>>arr[1] && arr[1]!=0)
		{
			stack<int>s;
			int A=1,B=1;
			for(int i=2;i<=n;i++)
				cin>>arr[i];
			int flag=1;
			while(B<=n)
			{
				if(A==arr[B])
					A++,B++;
				else if(!s.empty() && s.top()==arr[B])
					s.pop(),B++;
				else if(A<=n)
					s.push(A++);
				else 
				{
					flag=0;
					break;
				}
			}
			cout << (flag?"Yes":"No")<<endl;
		}
		cout <<endl;
	}
	return 0;
}
