#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
	int maxn=1e6;
	int t=clock();
	for(int i=0;i<maxn;i++)
		cout << i << endl;
	int t1=clock();
	for(int i=0;i<maxn;i++)
		printf("%d\n",i);
	cout << t <<" " << t1 << " " << clock()<<endl;
	return 0;
}
