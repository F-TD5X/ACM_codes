/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+100;

int T;
int n;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1009.in","r",stdin);
    //freopen("1009.out","w",stdout);
#endif
	scanf("%d",&T);
	int n0=0,n1=0;
	while(T--){
		n0=n1=0;
		scanf("%d",&n);
		for(int x,i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x%2)
				n1++;
			else 
				n0++;
		}
		if(n0 >= n1)
			printf("2 0\n");
		else
			printf("2 1\n");
	}
	return 0;
}
