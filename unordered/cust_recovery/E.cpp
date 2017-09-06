/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t[333];
ll sum,ans;
int n,k;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> t[i];
	priority_queue<int,vector<int>,greater<int>> q;
	int cnt=0;
	while(cnt < k)
		q.push(t[cnt++]);
	while(!q.empty()){
		sum+=q.top();
		q.pop();
		ans+=sum;
		if(cnt < n)
			q.push(t[cnt++]);
	}
	cout << ans << endl;
	return 0;
}
