/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char s1[13]={'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
char s2[4]={'C','D','H','S'};
int n;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.data.in","r",stdin);
    freopen("H.in","w",stdout);
#endif
	srand(time(0));
	n=rand()%52+1;
	cout << n << endl;
	for(int i=0;i<n;i++){
		putchar(s1[rand()%13]);
		putchar(s2[rand()%4]);
		cout << endl;
	}

	return 0;
}
