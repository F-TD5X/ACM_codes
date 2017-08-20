#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int maxn=1e4+10;
int n;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
#endif
	cin >> n;

	int t;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> t;
			if(i==j)
				cout << (int)(sqrt(t))<<" ";
		}
	}
	return 0;
}
