#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mp[4];
int all;
int pos;
int ans;


bool check(int id,int p)
{
	int tp=0;
	for(int i=0;i<id-1;i++)
		tp+=mp[i];
	tp+=p;
	for(int i=24-8;i>=0;i-=8){
		if(tp-i<0)
			tp=all-i+tp;
		if(tp+i==pos)
			return 1;
	}
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	for(int i=0;i<4;i++){
		cin >> mp[i];
		all+=mp[i];
	}
	int x,y;
	cin >> x >> y;
	for(int i=0;i<x-1;i++)
		pos+=mp[i];
	pos+=y;
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++){
			int id=(i+j-1)%4;
			int p=min(i,j);
			if(check(id,p))
				ans++;
		}
	cout << ans << endl;
	return 0;

}
