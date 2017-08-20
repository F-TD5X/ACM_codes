/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n,x,y,match;
string a,b;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
#endif
	cin >> T;
	while(T--){
		cin >> n >> x >> y;
		cin >> a >>b;
		match=0;
		for(int i=0;i<a.size();i++)
			if(a[i]==b[i])
				match++;
		bool flag=0;
		for(int left=n-match,i=0;i<=match;i++){
			if(x-i >=0 && y-i>=0){
				if(x-i +y-i<=n-match)
					flag=1;
			}
		}
		cout << (flag?"Not lying":"Lying")<<endl;
	}
	return 0;
}
