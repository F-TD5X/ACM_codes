#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4;
double l[maxn][maxn];
int px[maxn],py[maxn];
int n,T;

double len(int u,int v)
{
	return sqrt(pow((px[u]-px[v]),2.0)+pow((py[u]-py[v]),2.0));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("HDU-5533.in","r",stdin);
    //freopen("HDU-5533.out","w",stdout);
#endif
	cin >> T;
	while(T--)
	{
		cin >> n;
		double mi=0x3f3f3f3f;
		for(int i=0;i<n;i++)
			cin >> px[i] >> py[i];
		for(int i =0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(i!=j){
					l[i][j]=len(i,j);
					mi=min(l[i][j],mi);
				}
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(mi==l[i][j])
					cnt++;
		if(cnt == n)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
