/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int a,b,c,cnt=0;
	cin >> a >> b >> c;
	if((a==1 && b==1 && c==0)||(a==0 && b==0 && c==1))
		cout << 'C'<<endl;
	else if((a==1 && b==0 &&c==1)||(a==0 && b==1 && c==0))
		cout <<'B'<<endl;
	else if((a==0 && b==1 && c==1)||(a==1 && b==0 && c==0))
		cout <<"A"<<endl;
	else
		cout <<"*"<<endl;

	return 0;
}
