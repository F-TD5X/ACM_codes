#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[9]={4,3,5,6,4,6,5,4,3};
double e[100],r;
int w[100];
int ans=0;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		ans=0;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<c[i];j++)
				scanf("%d",w+j);
			for(int j=0;j<c[i];j++)
				scanf("%lf",e+j);
			for(int j=0;j<c[i];j++)
			{
				scanf("%lf",&r);
				if(e[j]>=3 && r>=3)
					ans+=w[j];	
			}
		}
		cout << ans << endl;
	}
	return 0;
}
