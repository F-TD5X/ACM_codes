#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF=1e9;
string s;
int n,k;

int check(int wid)
{
	int ret=0;
	int l=0;
	while(l<n){
		ret++;
		int r=l+wid;
		if(r>=n)
			break;
		while(r>l && s[r-1]!= '.' && s[r-1]!='-')r--;
		if(r==l)
			return INF;
		l=r;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> k;
	getchar();
	getline(cin,s);
	n=s.size();
	int l=0,r=n;
	for(int i=0;i<s.size();i++)
		if(s[i]==' ')
			s[i]='.';
	while(r-l>1){
		int m=(l+r)/2;
		if(check(m)<=k)
			r=m;
		else
			l=m;
	}
	cout << r << endl;
	return 0;
}
