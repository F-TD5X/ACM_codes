#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char mp[12][12];
int d[8][2]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};
bool check(int x, int y,char c)
{
	int cnt[4]={0};
	for(int t=1,i=0;i<8;i++,t=1){
		int xx=x+t*d[i][0],yy=y+t*d[i][1];
		while(xx>=1 && xx<=10 && yy>=1 && yy<=10 && mp[xx][yy] == c){
			t++;
			xx=x+t*d[i][0];
			yy=y+t*d[i][1];
			cnt[(i+4)%4]++;
		}
	}
	for(int i=0;i<4;i++){
		if(cnt[i] >=4)
			return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			cin >> mp[i][j];
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			if(mp[i][j]=='.')
				if(check(i,j,'X') || check(i,j,'0'))
					return 0*puts("YES");
	puts("NO");

	return 0;
}
