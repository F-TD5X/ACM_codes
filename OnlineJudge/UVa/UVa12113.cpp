#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char mp[100][100];
int len;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa12113.in","r",stdin);
    //freopen("UVa12113.out","w",stdout);
#endif
	while(cin >> n && n)
	{
		memset(mp,0,sizeof(mp));
		for(int i=0;i<5;i++)
			cin >> mp[i];
		for(len=1;len<=n;len++)
		{
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(mp[i][len+j]=='X' && mp[i][j]=='X')
						goto To;
				}
			}	
			break;
To:;
		}
		cout << (len+1)*10+n-len-1<<endl;
	}
	return 0;
}
