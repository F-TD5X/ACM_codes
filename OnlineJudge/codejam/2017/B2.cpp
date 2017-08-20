<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int kase=1;
string  s;

int check(string s)
{
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]<s[i-1])
			return i;
	}
	return -1;
}

void process(int pos)
{
	for(int i=pos;i>=0;i--){
		if(s[i]<'0' && i!=0){
			s[i]=10-('0'-s[i])+'0';
			s[i-1]--;
		}else if((s[i]<s[i-1]||s[i]=='0') && i!=0){
			s[i]='9';
			s[i-1]--;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		cin >> s;
		if(check(s)==-1){
			cout <<"Case #" << kase++ <<": "<<s<<endl;
			continue;
		}
		else{
			for(int i=0;i<s.size();i++)
			process(s.size()-1);
			printf("Case #%d: ",kase++);
			bool flag=0;
			for(int i=0;i<s.size();i++){
				if(!flag && s[i]<='0')
					continue;
				else if(!flag && s[i]>'0')
				{
					putchar(s[i]);
					flag=1;
				}
				else
					putchar(s[i]);
			}
			cout << endl;
		}
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int kase=1;
string  s;

int check(string s)
{
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]<s[i-1])
			return i;
	}
	return -1;
}

void process(int pos)
{
	for(int i=pos;i>=0;i--){
		if(s[i]<'0' && i!=0){
			s[i]=10-('0'-s[i])+'0';
			s[i-1]--;
		}else if((s[i]<s[i-1]||s[i]=='0') && i!=0){
			s[i]='9';
			s[i-1]--;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		cin >> s;
		if(check(s)==-1){
			cout <<"Case #" << kase++ <<": "<<s<<endl;
			continue;
		}
		else{
			for(int i=0;i<s.size();i++)
			process(s.size()-1);
			printf("Case #%d: ",kase++);
			bool flag=0;
			for(int i=0;i<s.size();i++){
				if(!flag && s[i]<='0')
					continue;
				else if(!flag && s[i]>'0')
				{
					putchar(s[i]);
					flag=1;
				}
				else
					putchar(s[i]);
			}
			cout << endl;
		}
	}
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int kase=1;
string  s;

int check(string s)
{
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]<s[i-1])
			return i;
	}
	return -1;
}

void process(int pos)
{
	for(int i=pos;i>=0;i--){
		if(s[i]<'0' && i!=0){
			s[i]=10-('0'-s[i])+'0';
			s[i-1]--;
		}else if((s[i]<s[i-1]||s[i]=='0') && i!=0){
			s[i]='9';
			s[i-1]--;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		cin >> s;
		if(check(s)==-1){
			cout <<"Case #" << kase++ <<": "<<s<<endl;
			continue;
		}
		else{
			for(int i=0;i<s.size();i++)
			process(s.size()-1);
			printf("Case #%d: ",kase++);
			bool flag=0;
			for(int i=0;i<s.size();i++){
				if(!flag && s[i]<='0')
					continue;
				else if(!flag && s[i]>'0')
				{
					putchar(s[i]);
					flag=1;
				}
				else
					putchar(s[i]);
			}
			cout << endl;
		}
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
