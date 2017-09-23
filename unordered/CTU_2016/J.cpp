/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[30];
string s1[30];
int n;
bool p[128];

void check(int st,int stand){
	for(int i=0;i<n;i++)
		p[s[stand][i]]=1;
	for(int i=0;i<n;i++){
		if(!p[s1[st][i]]){
			cout << i+1 <<" ";
			break;
		}
	}
	memset(p,0,sizeof(p));
	for(int i=0;i<n;i++){
		p[s1[st][i]]=1;
	}
	for(int i=0;i<n;i++){
		if(!p[s1[stand][i]]){
			cout << s1[stand][i] << endl;
			break;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("J.in","r",stdin);
    //freopen("J.out","w",stdout);
#endif
	while(cin >> n){
		memset(p,0,sizeof p);
		
		for(int i =0;i<n;i++){
			cin >> s[i];
			s1[i]=s[i];
			sort(s[i].begin(),s[i].end());
		}
		if(s[0]==s[1]){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(s[0][j]!=s[i][j]){
						cout << i+1 << " " ;
						check(i,0);
						goto END;
					}
				}
			}
		}
		else if(s[0] == s[2]){
			for(int j= 0;j<n;j++){
				if(s[1][j]!=s[2][j]){
					cout << 2 <<" ";
					check(1,0);
					goto END;
				}
			}
		}
		else if(s[1]==s[2]){
			for(int j=0;j<n;j++){
				if(s[0][j] != s[1][j]){
					cout << 1 <<" ";
					check(0,1);
					goto END;
				}
			}
		}
END:
		;
	}
	return 0;
}
