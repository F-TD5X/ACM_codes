/**Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
#include<regex>
using namespace std;
typedef long long ll;
int T;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1010.in","r",stdin);
    //freopen("1010.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		bool flag=1;
		string tmp="",s1,s2;
		cin >>s1 >>s2;
		for(int i=0;i<s2.size();i++){
			if(i+1<s2.size())
				if(s2[i]=='.' && s2[i+1]=='*')
					tmp += "(.)\\1*",++i;
				else
					tmp+=s2[i];
			else
				tmp+=s2[i];
		}
		if(regex_match(s1,regex(tmp)))
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
