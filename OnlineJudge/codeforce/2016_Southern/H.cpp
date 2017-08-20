#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[111],str;
int n,q;
int arr[111];
bool vis[111];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> s[i];
	for(int i=0;i<q;i++)
	{
		cin >> arr[i];
		if(i!=0 && s[arr[i]].size()!= s[arr[i-1]].size())
		{
			cout <<"No"<<endl;
			return 0;
		}
	}
	string ans="";
	int len=s[arr[0]].size();
	for(int i=0;i<len;i++)
	{
		bool flag=1;
		for(int j=0;j<q;j++)
		{
			vis[arr[j]]=1;
			if(j!=0 && s[arr[j-1]][i] != s[arr[j]][i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
			ans=ans+s[arr[0]][i];
		else
			ans=ans+'?';
	}
	bool flag=1;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i].size() !=ans.size())
			continue;
		else
		{
			int f=1;
			for(int j=0;j<len;j++)
			{
				if(ans[j]=='?' || ans[j]==s[i][j])
					continue;
				f=0;
			}
			if(f)
				num++;
		}
	}
	if(num == q)
	{
		cout <<"Yes"<<endl;
		cout << ans<<endl;
	}
	else
		cout <<"No"<<endl;
	return 0;
}
