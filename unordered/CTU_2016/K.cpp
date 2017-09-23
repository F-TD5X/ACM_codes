/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,char> mp;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("K.in","r",stdin);
    //freopen("K.out","w",stdout);
#endif
	mp[".-"]='A';mp["-..."]='B';mp["-.-."]='C';mp["-.."]='D';mp["."]='E';mp["..-."]='F';
	mp["--."]='G';mp["...."]='H';mp[".."]='I';mp[".---"]='J';mp["-.-"]='K';
	mp[".-.."]='L';mp["--"]='M';mp["-."]='N';mp["---"]='O';mp[".--."]='P';mp["--.-"]='Q';
	mp[".-."]='R';mp["..."]='S';mp["-"]='T';mp["..-"]='U';mp["...-"]='V';mp[".--"]='W';
	mp["-..-"]='X';mp["-.--"]='Y';mp["--.."]='Z';
	string s,ans;
	while(cin >> s){
		ans="";
		int t=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='/'){
				ans=ans+mp[s.substr(t,i-t)];
				t=i+1;
			}
			if(s[i]=='/' && s[i+1]=='/'){
				ans=ans+" ";
				t=i=i+2;
			}
			else if(s[i]=='/')
				i=i+1;
		}
		ans+=mp[s.substr(t,s.size()-t)];
		cout << ans << endl;
	}

	return 0;
}
