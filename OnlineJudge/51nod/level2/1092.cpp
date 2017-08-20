/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
int dp[1001][1001];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1092.in","r",stdin);
    //freopen("1092.out","w",stdout);
#endif
	cin >> s1;
	s2=s1;
	reverse(s2.begin(),s2.end());
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	cout << s1.size()-dp[s1.size()][s1.size()]<<endl;
	return 0;
}
