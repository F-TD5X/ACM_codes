#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
#endif
	int a;
	while(cin >> a)
	{
		if(a>100 || a<0)
			puts("Score is error!");
		else if(a <=100 && a>=90)
			cout <<"A"<<endl;
		else if(a<90 && a>=80)
			cout <<"B"<<endl;
		else if(a<80 && a>=70)
			cout <<"C"<<endl;
		else if(a < 70 && a>=60)
			cout <<"D"<<endl;
		else
			cout <<"E"<<endl;
	}
	return 0;
}
