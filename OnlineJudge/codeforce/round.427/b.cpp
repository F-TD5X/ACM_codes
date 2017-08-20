/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
char s[100050];
vector<int> v;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
#endif
	cin >> k >> s;
	int len=strlen(s);
	int t=0;
	for(int i =0;i<len;i++){
		t+=s[i]-'0';
		int tt=s[i]-'0';
		v.push_back(9-tt);
	}
	sort(v.begin(),v.end());
	int ans=0;
	while(t<k){
		t+=v.back();
		v.pop_back();
		ans++;
	}
	cout << ans << endl;

	return 0;
}
