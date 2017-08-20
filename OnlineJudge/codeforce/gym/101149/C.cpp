#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int p;
	cin >> p;
	for(int i=0,flag;i<p;i++,flag=0)
	{
		for(int j=i*i;j<(i+1)*(i+1);j++)
		{
			if(i%p == j%p)
			{
				cout << i <<" " << j << endl;
				cout << i%p<<" ";
				flag=1;
				break;
			}
		}
		if(!flag)
			cout << -1 <<" ";
	}
	return 0;
}
