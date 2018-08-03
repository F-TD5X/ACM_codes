#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;

int n,m;
int d[100][100] = {0};

void floyd(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i == j)
				d[i][j] = 0;

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[i][k] < INF && d[k][j] < INF)
					d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}

void input(){
	memset(d,0x3f,sizeof(d));
	cin >> n >> m;
	for(int u,v,c,i=0;i<m;i++){
		cin >> u >> v >> c;
		d[u][v]=d[v][u]=c;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("floyd.in","r",stdin);
    //freopen("floyd.out","w",stdout);
#endif

	input();
	floyd();

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(d[i][j] >= INF)
				cout << 0 <<" ";
			else
				cout << d[i][j] <<" ";
		cout <<endl;
	}

    return 0;
}

/*data
3 3
1 2 5
2 3 5
3 1 2
 */

