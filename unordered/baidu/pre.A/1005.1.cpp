/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cac(int y,int m,int d){
	if(m<3){
		y--;
		m=12+m;
	}
	int C=y/100+1;
	return (C/4-2*C+y+y/4+13*(m-1)/5+d-1)%7;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1005.1.in","r",stdin);
    //freopen("1005.1.out","w",stdout);
#endif
	int y,m,d;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d-%d-%d",&y,&m,&d);
		int t=cac(y,m,d);
		if(m==2 && d==29)
			y+=4;
		else
			y++;
		while(t!=cac(y,m,d)){
			if(m==2&& d==29)
				y+=4;
			else
				y++;
		}
		cout << y << endl;
	}

	return 0;
}
