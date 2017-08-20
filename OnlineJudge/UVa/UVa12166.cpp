#include<bits/stdc++.h>

using namespace std;
string s;
map<int,int> mp;
int sum;

void dfs(int d,int l,int r)
{
	if(s[l]=='[')
	{
		int p=0;
		for(int i=l+1;i!=r;i++)
		{
			if(s[i]=='[')
				p++;
			if(s[i]==']')
				p--;
			if(!p && s[i]==',')
			{
				dfs(d+1,l+1,i-1);
				dfs(d+1,i+1,r-1);
			}
		}		
	}
	else
	{
		long long w=0;
		for(int i=l;i<=r;i++)
			w=w*10+s[i]-'0';
		++sum,++mp[w<<d];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa12166.in","r",stdin);
    //freopen("UVa12166.out","w",stdout);
#endif
	int t;
	cin >>t;
	while(t--)
	{
		cin >>s;
		mp.clear();
		sum=0;
		dfs(0,0,s.size()-1);
		int maxn=0;
		for(auto a:mp)
			maxn=max(maxn,a.second);
		cout <<sum -maxn<<endl;
	}
	return 0;
}
