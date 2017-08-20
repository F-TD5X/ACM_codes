#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string ans="";
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	char t;
	int c=0;
	getchar();
	for(int i=0;i<n;i++){
		t=getchar();
		if(t=='1')
			c++;
		else if(t=='0' && c==0)
			ans=ans+'0';
		else if(t=='0'){
			ans=ans+char(c+'0');
			c=0;
		}
	}
	if(c==0)
		ans+='0';
	else
		ans+=(char)(c+'0');
	cout <<ans << endl;

	return 0;
}
