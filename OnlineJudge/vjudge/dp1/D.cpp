#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
const int inf = 1<<30;
string name;
struct
{
	string name;
	int dead,cost;
}obj[50];

struct Node
{
	int time,soc,pre,now;
}dp[1<<16];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> obj[i].name >> obj[i].dead>>obj[i].cost;
		}
		for(int i=1;i< (1<<n);i++){
			dp[i].soc=inf;
			for(int j=n-1;j>=0;j--){
				if(i &(1<<j)){
					int past=i-(1<<j);
					int st=dp[past].time+obj[j].cost-obj[j].dead;
					if(st<0)
						st=0;
					if(st +dp[past].soc < dp[i].soc){
						dp[i].soc=st+dp[past].soc;
						dp[i].now = j;
						dp[i].pre=past;
						dp[i].time=dp[past].time+obj[j].cost;
					}
				}
			}
		}
		stack<int> s;
		int tem=(1<<n)-1;
		cout << dp[tem].soc<<endl;
		while(tem){
			s.push(dp[tem].now);
			tem=dp[tem].pre;
		}
		while(!s.empty()){
			cout << obj[s.top()].name<<endl;
			s.pop();
		}
	}
	return 0;
}
