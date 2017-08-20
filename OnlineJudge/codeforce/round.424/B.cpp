#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char mp[1000];
string s1,s2,s3;
bool upper;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> s1 >> s2;
	for(int i=0;i<s1.size();i++){
		mp[s1[i]]=s2[i];
		mp[s1[i]-'a'+'A']=s2[i]-'a'+'A';
	}
	cin >> s3;
	for(int i=0;i<s3.size();i++){
		if((s3[i]>='A' && s3[i]<='Z') || (s3[i]>='a' && s3[i]<='z'))
			cout<< mp[s3[i]];
		else
			cout << s3[i];
	}

	return 0;
}
