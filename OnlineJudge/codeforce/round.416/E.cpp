#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+10;
int n,m,q,l,r;
int mp[15][maxn];

struct Node{
	int sum;
	int a[15],b[15];
}tree[maxn<<2];

int f[maxn<<2],id[maxn<<2];

int fi(int x){
	return f[x]==x?x:f[x]=fi(x);
}

void mge(Node &rt,Node &l,Node &r,int lpos,int rpos){
	rt.sum=l.sum+r.sum;
	for(int i=0;i<15;i++){
		f[i]=l.a[i];
		f[i+15]=l.b[i];
		f[i+15*2]=r.a[i]+15*2;
		f[i+15*3]=r.b[i]+15*2;
	}
	for(itn i=0;i<15;i++){

	}
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> n >> m >>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> mp[i][j];
	build();
	return 0;
}
