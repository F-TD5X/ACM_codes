#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+20,z=26;
int n;
bool good[z];
string goods,path;
bool check(string path,string s){
	if(path.size()!=s.size())
		return 0;
	for(int i=0;i<s.size();i++){
		if(path[i]!='?'){
			if(s[i]!=path[i])
				return 0;
		}else
			if(!good[s[i]-'a'])
				return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> goods>>path>>n;
	for(auto c:goods)
		good[c-'a']=1;
	auto pos=path.find('*');
	for(string s;n--;){
		cin >> s;
		if(s.size()<path.size()-1)
			puts("NO");
		else if(pos==string::npos)
			cout << (check(path,s)?"YES":"NO")<<endl;
		else {
			bool flag=1;
			flag &=check(path.substr(0,pos),s.substr(0,pos));
			reverse(s.begin(),s.end());
			reverse(path.begin(),path.end());
			pos=path.size()-pos-1;
			flag &=check(path.substr(0,pos),s.substr(0,pos));
			reverse(s.begin(),s.end());
			reverse(path.begin(),path.end());
			pos=path.size()-pos-1;
			for(int i=pos;i<s.size()-(path.size()-pos-1);i++)
				flag&=!good[s[i]-'a'];
			if(flag)
				cout <<"YES"<<endl;
			else
				cout <<"NO"<<endl;
		}
	}

	return 0;
}
