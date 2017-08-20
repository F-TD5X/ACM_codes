#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[27];
const int maxn=5e5+10;
string s;
int n;
int cnt1;
bool ok()
{
	return (cnt1==26);
}

void fll()
{
	for(int i=0;i<n;i++)
		if(s[i]=='?')
			s[i]=='A';
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >>s;
	n=s.size();
	if(n<26)
	{
		puts("-1");
		return 0;
	}
	cnt1=0;
	for(int i=0;i<26;i++)
	{
		if(s[i]=='?')
		{
			cnt1++;
			continue;
		}
		cnt[s[i]-'A']++;
		if(cnt[s[i]-'A']==1)
			cnt1++;
	}
	if(ok())
	{
		int cur=0;
		while(cnt[cur]>0)
			cur++;
		for(int i=0;i<26;i++)
		{
			if(s[i]=='?')
			{
				s[i]=cur+'A';
				cur++;
				while(cnt[cur]>0)
					cur++;
			}
		}
		fll();
		cout <<s<<endl;
		return 0;
	}
	for(int i=26;i<n;i++)
	{
		if(s[i]=='?')
		{
			cnt[s[i]-'A']++;
			if(cnt[s[i]-'A']==1)
				cnt1++;
		}
		if(s[i-26]!='?')
		{
			cnt[s[i-26]-'A']--;
			if(cnt[s[i-26]-'A']==0)
				cnt1--;
		}
		if(s[i-26]=='?')
			cnt1--;
		if(s[i]=='?')
			cnt1++;
		if(ok())
		{
			int cur=0;
			while(cnt[cur]>0)
				cur++;
			for(int j=i-25;j<=i;j++)
			{
				if(s[j]=='?')
				{
					s[j]=cur+'A';
					cur++;
					while(cnt[cur]>0)
						cur++;
				}
			}
			fll();
			cout <<s<<endl;
			return 0;
		}
	}
	cout <<-1 <<endl;
	return 0;
}
