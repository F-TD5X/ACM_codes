#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int status;
int bef;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	cin >> bef;
	status=0;
	bool flag=1;
	for(int t,i=1;i<n;i++){
		cin >> t;
		if(t > bef && status==0){
			bef=t;
		}
		else if(t==bef && status!=2){
			status=1;
		}
		else if(t < bef && (status == 2 || status == 1 || status==0)){
			bef=t;
			status=2;
		}
		else
			flag=0;
	}
	if(flag)
		puts("YES");
	else
		puts("NO");

	return 0;
}
