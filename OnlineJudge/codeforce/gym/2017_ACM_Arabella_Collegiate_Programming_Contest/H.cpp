#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mp[222];
int n;
string s;
bool flag;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
	mp['A']=mp['H']=mp['I']=mp['M']=mp['O']=mp['T']=mp['U']=mp['V']=mp['W']=mp['X']=mp['Y']=1;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s;
		flag=1;
		for(int i=0;i<s.size();i++)
			if(!mp[s[i]])
				flag=0;
		int l=0,r=s.size()-1;
		while(l<=r){
			if(s[l]!= s[r])
				flag=0;
			l++,r--;
		}
		if(flag)
			puts("yes");
		else
			puts("no");
	}

	return 0;
}
