/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[7],b[7];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("K.in","r",stdin);
    //freopen("K.out","w",stdout);
#endif
	for(int i=0;i<6;i++)
		cin >> a[i];
	for(int i=0;i<6;i++)
		cin >> b[i];
	double win=0,lose=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(a[i]!=b[j]){
				if(a[i]>b[j])
					win+=1;
				else
					lose+=1;
			}
		}
	}
	printf("%.5f\n",win/(win+lose));
	return 0;
}
