/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,r;
int vis[100100];
int num,ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n >> k>> r;
	for(int x,i=0;i<k;i++){
		cin >> x;
		vis[x]=1;
	}
	for(int i=1;i<=r;i++)
		num+=vis[i];
	ans+=max(0,2-num);
	for(int i=r;i>=1;i--){
		if(num==2)
			break;
		if(!vis[i])
			vis[i]=1,num++;
	}
	for(int i=r+1;i<=n;i++){
		num=num-vis[i-r]+vis[i];
		if(num < 2)
			vis[i]=1,ans++,num=2;
	}
	cout << ans << endl;
	return 0;
}
