#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[105][105];
int p[110];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
			a[i][j]--;
		}
	for(int i=0;i<m;i++)
		for(int j=0;j<i+1;j++)
		{
			for(int k=0;k<m;k++)
				p[k]=k;
			swap(p[i],p[j]);
			bool flag=0;
			for(int k=0;k<n;k++)
			{
				int cnt=0;
				for(int l=0;l<m;l++)
					if(a[k][l]!=p[l])
						++cnt;
				if(cnt>2)
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				cout <<"YES"<<endl;
				return 0;
			}
		}
	cout <<"NO"<<endl;
	return 0;
}
