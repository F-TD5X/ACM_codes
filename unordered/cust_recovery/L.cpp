/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a;
struct Node{
	int x,y;
	bool operator<(const Node &t)const{
		if(y==t.y)
			return x<t.x;
		return y<t.y;
	}
}s[3];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("L.in","r",stdin);
    //freopen("L.out","w",stdout);
#endif
	for(int i=0;i<3;i++){
		cin >> s[i].x >> s[i].y;
		if(s[i].x>s[i].y)
			swap(s[i].x,s[i].y);
		a=max(a,max(s[i].y,s[i].x));
	}
	sort(s,s+3);
	if(s[0].y == a && s[1].y== a && s[0].x+s[1].x+s[2].x == a){
		puts("YES");
		return 0;
	}
	else if((s[0].y==s[1].y && s[0].x+s[1].x == a && s[2].x+s[1].y==a)||
			(s[0].x==s[1].x && s[0].y+s[1].y==a && s[2].x + s[0].x == a)||
			(s[0].x+s[1].y==a && s[0].y==s[1].x && s[2].x+s[0].y==a)||
			(s[0].x+s[1].y==a  && s[0].y==s[1].x && s[2].x+s[1].x == a)){
		puts("YES");
		return 0;
	}
	else
		puts("NO");

	return 0;
}
