<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;

struct KMP{
	string t;
	int tlen;
	int next[maxn];
	int cnt;
	void pre_next(string t){
		this->t=t;
		memset(next,0,sizeof(next));
		for(int i=1,j=0;i<t.size();i++){
			j=next[i];
			while(j && t[i]!=t[j])
				j=next[j];
			next[i+1]=(t[i]==t[j])?j+1:0;
		}
	}
	int find(string s){
		for(int j=0,i=0;i<s.size();i++){
			while(j && s[i]!=t[j])
				j=next[j];
			if(s[i]==t[j])
				j++;
			if(j==t.size())
				cnt++;
		}
		return cnt;
	}
}kmp;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("103.in","r",stdin);
    //freopen("103.out","w",stdout);
#endif
	string s,t;
	cin >> s >> t;
	kmp.pre_next(t);
	cout << kmp.find(s) << endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;

struct KMP{
	string t;
	int tlen;
	int next[maxn];
	int cnt;
	void pre_next(string t){
		this->t=t;
		memset(next,0,sizeof(next));
		for(int i=1,j=0;i<t.size();i++){
			j=next[i];
			while(j && t[i]!=t[j])
				j=next[j];
			next[i+1]=(t[i]==t[j])?j+1:0;
		}
	}
	int find(string s){
		for(int j=0,i=0;i<s.size();i++){
			while(j && s[i]!=t[j])
				j=next[j];
			if(s[i]==t[j])
				j++;
			if(j==t.size())
				cnt++;
		}
		return cnt;
	}
}kmp;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("103.in","r",stdin);
    //freopen("103.out","w",stdout);
#endif
	string s,t;
	cin >> s >> t;
	kmp.pre_next(t);
	cout << kmp.find(s) << endl;
	return 0;
}
>>>>>>> 15efef77bd5e792465c034dce28c633a41daf492
