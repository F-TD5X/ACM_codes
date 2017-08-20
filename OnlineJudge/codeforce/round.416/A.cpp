#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int a,b;
	cin >> a >>b;
	for(int i=1,t1=0,t2=0;1;i++){
		if(i%2)
			t1+=i;
		else
			t2+=i;
		if(t2 > b){
			cout <<"Valera"<<endl;
			return 0;
		}
		else if(t1 > a){
			cout <<"Vladik"<<endl;
			return 0;
		}
	}
	return 0;
}
