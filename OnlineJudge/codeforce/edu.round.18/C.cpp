<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum;
string s;

string doit(string s)
{
	if(s.size()==0)
		return "-1";
	ll len=0;
	while(len<s.size() && s[len]=='0')
		len++;
	if(len>=s.size())
		len--;
	return s.substr(len);
}

string erase(string s,int pos)
{
	return s.substr(0,pos)+s.substr(pos+1);
}
string solve(string s)
{
	ll cnt=0;
	for(int j=0;j<2;j++)
	{
		for(int i=s.size()-1;i>=0;i--)
		{
			if((s[i]-'0')%3 + sum%3==3)
			{
				s=erase(s,i);
				++cnt;
				break;
			}
		}
	}
	if(cnt==2)
		return doit(s);
	return "-1";
}
string solve()
{
	for(int i=0;i<s.size();i++)
		sum+=s[i]-'0';
	if(sum%3==0)
		return s;
	else
	{
		string s1="",s2="";
		s1=solve(s);
		for(int i=s.size()-1;i>=0;i--)
		{
			if((s[i]-'0')%3 == sum%3)
			{s2= doit(erase(s,i));break;}
		}
		if(s1!="" || s2!="")
			if(s1.size()<s2.size() || (s1=="-1"&& s2!=""))
				return s2;
			else
				return s1;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> s;
	cout << solve()<<endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum;
string s;

string doit(string s)
{
	if(s.size()==0)
		return "-1";
	ll len=0;
	while(len<s.size() && s[len]=='0')
		len++;
	if(len>=s.size())
		len--;
	return s.substr(len);
}

string erase(string s,int pos)
{
	return s.substr(0,pos)+s.substr(pos+1);
}
string solve(string s)
{
	ll cnt=0;
	for(int j=0;j<2;j++)
	{
		for(int i=s.size()-1;i>=0;i--)
		{
			if((s[i]-'0')%3 + sum%3==3)
			{
				s=erase(s,i);
				++cnt;
				break;
			}
		}
	}
	if(cnt==2)
		return doit(s);
	return "-1";
}
string solve()
{
	for(int i=0;i<s.size();i++)
		sum+=s[i]-'0';
	if(sum%3==0)
		return s;
	else
	{
		string s1="",s2="";
		s1=solve(s);
		for(int i=s.size()-1;i>=0;i--)
		{
			if((s[i]-'0')%3 == sum%3)
			{s2= doit(erase(s,i));break;}
		}
		if(s1!="" || s2!="")
			if(s1.size()<s2.size() || (s1=="-1"&& s2!=""))
				return s2;
			else
				return s1;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> s;
	cout << solve()<<endl;
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum;
string s;

string doit(string s)
{
	if(s.size()==0)
		return "-1";
	ll len=0;
	while(len<s.size() && s[len]=='0')
		len++;
	if(len>=s.size())
		len--;
	return s.substr(len);
}

string erase(string s,int pos)
{
	return s.substr(0,pos)+s.substr(pos+1);
}
string solve(string s)
{
	ll cnt=0;
	for(int j=0;j<2;j++)
	{
		for(int i=s.size()-1;i>=0;i--)
		{
			if((s[i]-'0')%3 + sum%3==3)
			{
				s=erase(s,i);
				++cnt;
				break;
			}
		}
	}
	if(cnt==2)
		return doit(s);
	return "-1";
}
string solve()
{
	for(int i=0;i<s.size();i++)
		sum+=s[i]-'0';
	if(sum%3==0)
		return s;
	else
	{
		string s1="",s2="";
		s1=solve(s);
		for(int i=s.size()-1;i>=0;i--)
		{
			if((s[i]-'0')%3 == sum%3)
			{s2= doit(erase(s,i));break;}
		}
		if(s1!="" || s2!="")
			if(s1.size()<s2.size() || (s1=="-1"&& s2!=""))
				return s2;
			else
				return s1;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> s;
	cout << solve()<<endl;
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
