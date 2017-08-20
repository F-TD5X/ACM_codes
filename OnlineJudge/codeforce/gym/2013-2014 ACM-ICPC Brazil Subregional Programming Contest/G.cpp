/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=333;
int mp1[maxn][maxn],mp2[maxn][maxn];

int f[maxn*maxn];

int fi(int x){
	if(f[x]!=x)
		f[x]=fi(f[x]);
	return f[x];
}

void init()
{
	for(int i=0;i<=303*303;i++)
		f[i]=i;
}

void uni(int a,int b){
	a=fi(a),b=fi(b);
	if(a!=b)
		f[a]=b;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
	int ans=0,ans1=0,t=0;
	bool flag=0;
	cin >> n >> m;
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin >> mp1[i][j];
			mp2[i][j]=mp1[i][j];
		}
	for(int i=1;i<=n;i++){
		sort(mp1[i]+1,mp1[i]+1+m);
		t=0;
		for(int j=1;j<=m;j++){
			if(j < m)
				if(mp1[i][j+1]-mp1[i][j] !=1)
					flag=1;
			if(fi(mp1[i][j])==fi(mp2[i][j]))
				t++;
			else
				f[fi(mp1[i][j])]=fi(mp2[i][j]);
		}
		if(ans==0)
			ans=m-t;
		else if(ans!=m-t)
			flag=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mp1[j][i]=mp2[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			mp2[i][j]=mp1[i][j];
	t=0;
	init();
	for(int i=1;i<=m;i++){
		sort(mp1[i]+1,mp1[i]+1+n);
		t=0;
		for(int j=1;j<=n;j++){
			if(j<n)
				if(mp1[i][j+1] -mp1[i][j] != m)
					flag=1;
			if(fi(mp1[i][j]) == fi(mp2[i][j]))
				t++;
			else
				uni(mp1[i][j],mp2[i][j]);
		}
		if(ans1==0)
			ans1=n-t;
		else if(ans1!=n-t)
			flag=1;
	}
	if(flag)
		cout <<"*"<<endl;
	else
		cout << ans+ans1<<endl;
	return 0;
}
