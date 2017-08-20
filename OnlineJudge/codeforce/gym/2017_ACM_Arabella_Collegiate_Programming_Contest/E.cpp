#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e7+100;
int t[maxn/2],p[maxn/2],pcnt;
int sg[maxn],T,pos;

void init(){
	for(int i=2;i<=maxn/2;i++)
		if(p[i])
			continue;
		else
			for(int k=2;i*k<maxn/2;k++)
				t[i*k]=1;
	for(int i=1;i<=maxn/2;i++)
		if(!t[i])
			p[pcnt++]=i;
	sg[1]=1;sg[2]=2;sg[3]=1;
	for(int i=4;i<=maxn;i++){
		pos= lower_bound(p,p+pcnt,i/2)-p;
		for(int j=pos;j>=0;j--){
			if(sg[i-j]==2){
				sg[i]=1;
				goto EXT;
			}
		}
EXT:;
	}
	cout << "INIT2"<<endl;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> T;
	init();
	int n;
	while(T--){
		cin >> n;
		cout << n<<endl;
	}
	return 0;
}
