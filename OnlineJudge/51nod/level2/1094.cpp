/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
ll a[maxn];
ll pre[maxn];
ll k;
int n;
map<ll,int> mp;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1094.in","r",stdin);
    //freopen("1094.out","w",stdout);
#endif
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pre[i]=pre[i-1]+a[i];
		mp[pre[i]]=i;
	}
	bool flag=1;
	for(int i=0;i<=n;i++){
		if(mp[pre[i]+k] >i+1)
			for(int j=i;j<=n;j++)
				if(pre[j]-pre[i] == k){
					flag=0;
					cout << i+1 <<" " << j << endl;
				}
	}
	if(flag)
		cout <<"No Solution"<<endl;
	return 0;
}
