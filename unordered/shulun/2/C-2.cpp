#include<bits/stdc++.h>
using namespace std;
main(){
	int n,j,k,l=1;
	scanf("%d%d",&n,&k);
	while(n--){
		scanf("%d",&j);
		j=std::__gcd(j,k);
		cout << j << endl;
		l=l/std::__gcd(l,j)*j;
		cout <<l << endl;
		cout <<endl;
	}
	puts(l-k?"No":"Yes");
}
